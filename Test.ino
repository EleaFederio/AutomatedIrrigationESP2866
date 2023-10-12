int soilMoistureSensorPin = A0;
int pumpPin = LED_BUILTIN;
int moistureThreshold = 20;
int pauseDuration = 20000;

void setup(){
  pinMode(soilMoistureSensorPin, INPUT);
  pinMode(pumpPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  long sensorReading = analogRead(soilMoistureSensorPin);
  long moistureContent = map(sensorReading, 1024, 700, 0, 100);
  Serial.print("Soil Moisture Content: ");
  Serial.print(moistureContent);
  Serial.println("%");
  if(moistureContent < moistureThreshold){
    Serial.println("The moisture content of the soil is less than the threshold...");
    waterThePlant(pauseDuration, 500);
  }
  delay(1000);
}

void waterThePlant(int pause, int wateringDuration){
  digitalWrite(pumpPin, LOW);
  Serial.println("Watering the plant...");
  delay(wateringDuration);
  digitalWrite(pumpPin, HIGH);
  Serial.println("Waiting for the soil to absorb water...");
  delay(pause);
}