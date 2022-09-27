#include <LiquidCrystal_I2C.h>

String payload = "Rapaiz!!";
int compareSize;
int delayTime = 1000;

LiquidCrystal_I2C lcd(0x27,20,4);

void setup()
{
  lcd.init();
  lcd.backlight();
  compareSize = 16 - payload.length();
}

void changePayload()
{
    lcd.setCursor(0, 0);
    lcd.print(payload);
}  

void loop()
{
    changePayload();
  
    for(int position = 0; position < compareSize; position++)
    {
      lcd.scrollDisplayRight();
      delay(delayTime);
    }
  
    for(int position = 0; position < compareSize; position++)
    {
      lcd.scrollDisplayLeft();
      delay(delayTime);
    }
}
