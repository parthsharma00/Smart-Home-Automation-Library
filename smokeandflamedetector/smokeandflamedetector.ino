/* Safety System: Rain & Gas Detection
   - LED Rain (Pin 12): Turns ON when rain is detected.
   - LED Gas (Pin 13): Turns ON when gas/smoke is detected.
   - Buzzer (Pin 11): Rings if EITHER sensor is triggered.
*/

// Define Pins
const int rainSensorPin = 2;  
const int gasSensorPin = A2;   
const int buzzerPin = 11;
const int ledRain = 12;
const int ledGas = 13;

// Calibration
int gasThreshold = 150; 

void setup() {
  pinMode(rainSensorPin, INPUT);
  pinMode(ledRain, OUTPUT);
  pinMode(ledGas, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Start with everything OFF
  digitalWrite(ledRain, LOW);
  digitalWrite(ledGas, LOW);
  digitalWrite(buzzerPin, LOW);
  
  Serial.begin(9600);
  Serial.println("System Monitoring Active...");
}

void loop() {
  // 1. READ SENSORS
  // Most HW-484 modules output LOW when wet and HIGH when dry
  bool isRainy = (digitalRead(rainSensorPin) == HIGH); 
  
  int gasValue = analogRead(gasSensorPin);
  bool isGassy = (gasValue > gasThreshold);

  // 2. ACT ON RAIN SENSOR
  if (isRainy) {
    digitalWrite(ledRain, HIGH);
  } else {
    digitalWrite(ledRain, LOW);
  }

  // 3. ACT ON GAS SENSOR
  if (isGassy) {
    digitalWrite(ledGas, HIGH);
  } else {
    digitalWrite(ledGas, LOW);
  }

  // 4. BUZZER LOGIC (The "OR" Logic)
  // If it is raining OR if there is gas, turn on the buzzer
  if (isRainy || isGassy) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }

  // 5. DEBUGGING
  Serial.print("Gas Level: "); Serial.print(gasValue);
  Serial.print(" | Rain Status: "); 
  Serial.println(isRainy ? "WATER DETECTED" : "DRY");

  delay(100); // Short delay for stability
}