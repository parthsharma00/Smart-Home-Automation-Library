#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9
#define LED_PIN 8 
#define BUZZER_PIN 7
#define SERVO_PIN 6

MFRC522 rfid(SS_PIN, RST_PIN);
Servo myServo;

byte authorizedTag[] = {0x62, 0x7E, 0x3E, 0x5C}; 

// --- CALIBRATION SETTINGS ---
int stopSignal = 90;   // The signal that tells the motor to STOP
int turnDelay = 130;   // ADJUST THIS: How long (ms) to spin to reach 90 degrees
// ----------------------------

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  
  myServo.attach(SERVO_PIN);
  myServo.write(stopSignal); 
  
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  Serial.println("System Ready...");
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) return;

  bool accessGranted = true;
  for (byte i = 0; i < 4; i++) {
    if (rfid.uid.uidByte[i] != authorizedTag[i]) {
      accessGranted = false;
      break;
    }
  }

  if (accessGranted) {
    handleSuccess();
  } else {
    handleDenied();
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}

void handleSuccess() {
  Serial.println("ACCESS GRANTED");

  // 1. ROTATE 90 DEGREES (APPROX)
  myServo.write(180);       // Start spinning full speed
  delay(turnDelay);         // Spin just long enough to hit 90 degrees
  myServo.write(stopSignal); // STOP
  
  // 2. ALERT PHASE
  digitalWrite(LED_PIN, HIGH);
  tone(BUZZER_PIN, 1500);
  delay(3000);              // Your 3-second beep/light
  noTone(BUZZER_PIN);
  digitalWrite(LED_PIN, LOW);

  // 3. ROTATE BACK
  Serial.println("Relocking...");
  myServo.write(0);         // Spin opposite way
  delay(turnDelay);         // Spin back the same amount
  myServo.write(stopSignal); // STOP
}

void handleDenied() {
  for(int i = 0; i < 3; i++) {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 400); 
    delay(200);
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
    delay(200);
  }
}