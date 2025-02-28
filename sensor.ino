float temp; 
int sensorValue;


const int ledPin = 13;        
const int motorPin = 12;      

void setup() {
  pinMode(ledPin, OUTPUT);     
  pinMode(motorPin, OUTPUT);   
  Serial.begin(9600);          
  Serial.println("###Temperature monitor###");
}

void loop() {
  sensorValue = analogRead(A0); 
  Serial.print("Sensor value: ");
  Serial.println(sensorValue);
  delay(2000);

  
  temp = sensorValue * (5.0 / 1023.0) * 100.0; 
  Serial.print("Temp value: ");
  Serial.println(temp);
  delay(2000);
  
  
  if (temp < 5) {
    digitalWrite(ledPin, HIGH); 
    delay(500);                 
    digitalWrite(ledPin, LOW);  
    delay(500);                 
  }
  
  else if (temp >= 6 && temp <= 25) {
    digitalWrite(ledPin, LOW);   
    digitalWrite(motorPin, LOW); 
  }
  
  else if (temp > 25) {
    digitalWrite(ledPin, HIGH); 
    digitalWrite(motorPin, HIGH); 
  }
  }
