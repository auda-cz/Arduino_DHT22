#include <DHT.h>
DHT dht(2,DHT22);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity(); // Gets the values of the humidity
  delay(2000);
  float t = dht.readTemperature(); // Gets the values of the temperature
  
  
  // Printing the results on the serial monitor
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print(" °C ");
  Serial.print("    Humidity = ");
  Serial.print(h);
  Serial.println(" % ");
  
  delay(2000);
}
