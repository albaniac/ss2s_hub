#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
	// initialize the LCD
	lcd.begin();
	// Turn on the blacklight
	//lcd.backlight();

	// print a message.
	lcd.clear();
	lcd.print("      GROW     ");
  	lcd.setCursor(0, 1);
  	lcd.print("     HACKER    ");
  	delay(3000);
 	lcd.clear();
	lcd.print("Test text 12345");
  	lcd.setCursor(0, 1);
  	lcd.print("Test text 56789");
}

void loop()
{
	// Do nothing here...
}
