const int rainPin = A0;    
const int buzzerPin = 11;  
const int threshold = 500; 

// Motor Pins (L298N)
const int motorPin1 = 8;
const int motorPin2 = 9;

// State tracking
bool isRaining = false;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  Serial.println("System Ready: Monitoring Rain...");
}

void loop() {
  int sensorValue = analogRead(rainPin);
  
  // Transition to RAIN
  if (sensorValue < threshold && !isRaining) {
    isRaining = true;
    rainDetectedAction();
  } 
  // Transition to CLEAR
  else if (sensorValue >= threshold && isRaining) {
    isRaining = false;
    rainClearedAction();
  }

  delay(200); 
}

void rainDetectedAction() {
  Serial.println("ALERT: Rain! Motor moving forward...");
  digitalWrite(buzzerPin, HIGH); // Alarm ON
  
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  delay(200); // Amount of rotation
  
  stopMotor();
  digitalWrite(buzzerPin, LOW); // Alarm ON

}

void rainClearedAction() {
  Serial.println("Status: Clear. Motor reversing...");
  digitalWrite(buzzerPin, HIGH); // Alarm OFF
  
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW); // Fixed the typo here
  delay(200); // Amount of rotation
  
  stopMotor();
  digitalWrite(buzzerPin, LOW); // Alarm ON

}

void stopMotor() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}