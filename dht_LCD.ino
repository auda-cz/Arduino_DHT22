#include <LiquidCrystal.h>
#include "Adafruit_SHTC3.h"
//initialize libraries

LiquidCrystal lcd(12,11,10,9,8,7);  //connected to LCD pin:(rs, en, d4, d5, d6, d7);
Adafruit_SHTC3 shtc3 = Adafruit_SHTC3();
float T,RH;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  lcd.begin(16,2);
  while(!shtc3.begin())
  {
    lcd.setCursor(0, 0);
    lcd.print("No senser");
    delay(100);
  }
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  sensors_event_t humidity, temp;
  shtc3.getEvent(&humidity, &temp);
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print("Temp = ");lcd.print(temp.temperature);lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Hum  = ");lcd.print(humidity.relative_humidity);lcd.print(" %");
  delay(22000);
}
