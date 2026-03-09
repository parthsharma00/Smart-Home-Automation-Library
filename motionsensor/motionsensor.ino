// Pin Definitions
const int sensorPin = 3;  // Sensor OUT connected to Pin 3
const int ledPin = 13;    // LED connected to Pin 13
const int buzzerPin = 8;  // Buzzer connected to Pin 8

void setup() {
  pinMode(sensorPin, INPUT);   // Set sensor as input
  pinMode(ledPin, OUTPUT);    // Set LED as output
  pinMode(buzzerPin, OUTPUT); // Set Buzzer as output
  
  Serial.begin(9600);         // Start serial monitor to see status
  
  // WARM UP PHASE
  Serial.println("Sensor warming up... stay still for 30-60 seconds");
  delay(30000);               // Wait 30 seconds for the sensor to stabilize
  Serial.println("Sensor Active!");
}

void loop() {
  int sensorValue = digitalRead(sensorPin); // Read the sensor

  if (sensorValue == HIGH) {
    // If motion is detected
    digitalWrite(ledPin, HIGH);    // Turn LED on
    digitalWrite(buzzerPin, HIGH); // Turn Buzzer on
    Serial.println("--- MOTION DETECTED! ---");
  } 
  else {
    // If no motion is detected
    digitalWrite(ledPin, LOW);     // Turn LED off
    digitalWrite(buzzerPin, LOW);  // Turn Buzzer off
    Serial.println("Scanning...");
  }

  delay(100); // Small delay for stability
}