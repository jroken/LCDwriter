#include <LiquidCrystal_I2C.h>

String data;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  Serial.begin(9600);
  Serial.print("Program basladiii");

  lcd.begin(); 
  lcd.backlight(); 
  //lcd.setCursor(0,0); //imleci 1.satır ilk karaktere getiriyoruz.
  //lcd.print("Burak <3"); //İlk satıra yazalım
  //lcd.setCursor(0,1); //imleci 2.satır ilk karaktere getiriyoruz.
  //lcd.print("AAAAAAAAAAAA"); /
}



void loop() {
  while(Serial.available()) {
    data = Serial.read();
  }
  lcd.setCursor(0,0);
  lcd.print(data);
}
