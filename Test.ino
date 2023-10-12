
int soilMoistureSensorPin = A0;
int pumpPin = D2;
int moistureThreshold = 35;
int pauseDuration = 20000;

void setup() {
  pinMode(soilMoistureSensorPin, INPUT);
  pinMode(pumpPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float sensorReading = analogRead(soilMoistureSensorPin);
  float moistureContent = map(sensorReading, 1024, 633, 0, 100);
  Serial.print("Soil Moisture ");
  Serial.print(moistureContent);
  Serial.println("%");
  if(moistureContent < moistureThreshold){
    digitalWrite(pumpPin, HIGH);
    Serial.println("Watering the Plant... ");
    delay(500);
    digitalWrite(pumpPin, LOW);
    Serial.println("Pause for 20 sec.. ");
    delay(pauseDuration);
  }
  delay(1000);
}