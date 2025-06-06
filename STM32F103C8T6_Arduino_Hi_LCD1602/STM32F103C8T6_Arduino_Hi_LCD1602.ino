/*
  STM32F103C8 board testing
  LCD1602 4-bit mode, demo the use a 16x2 LCD display.  The LiquidCrystal
  library works with all LCD displays that are compatible with the
  Hitachi HD44780 driver.
  
  This sketch prints LCD "Hi xiaolaba !", update every second
  LED (connected to PC13) blinking 1Hz

## STM32F103C8 or STM32F103CB, LQFP 48 pin, pin number is map to pin number of the IC
  The circuit:
LCD1602  | STM32F103
---------+--------------
VSS      | GND
VDD      | +5v
CONTRAST | GND
RS       | PA5
R/W      | GND
Enable   | PA4
D0       | no connection 
D1       | no connection 
D2       | no connection 
D3       | no connection 
D4       | PA3 
D5       | PA2 
D6       | PA1
D7       | PA0
LED+     | +5V
*/

// include the library code:
#include <LiquidCrystal.h>

/*
// working good STM32F103C8
// LCD1602 pin# vs STM32F103C8 pin#
#define rs PA5
#define en PA4
#define d4 PA3
#define d5 PA2
#define d6 PA1
#define d7 PA0
*/

// working good for STM32F103C8
const int rs = PA5, en = PA4, d4 = PA3, d5 = PA2, d6 = PA1, d7 = PA0;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define LED_pin PC13

void setup() {
  pinMode(LED_pin, OUTPUT);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hi, xiaolaba !");
}


void loop() {
  static unsigned long lastToggle = 0; // Track last toggle time
  static unsigned long lastLcdUpdate = 0; // Track last LCD update time
  const unsigned long toggleInterval = 500; // 500ms for LED toggle
  const unsigned long lcdInterval = 1000; // 1000ms for LCD update

  unsigned long currentMillis = millis(); // Current time

  // Toggle LED every 500ms
  if (currentMillis - lastToggle >= toggleInterval) {
    digitalWrite(PC13, !digitalRead(PC13)); // Toggle pin state
    lastToggle = currentMillis; // Update last toggle time
  }

  // Update LCD every 1000ms
  if (currentMillis - lastLcdUpdate >= lcdInterval) {
    lcd.setCursor(0, 1); // Set cursor to column 0, line 1
    lcd.print(currentMillis / 1000); // Print seconds since reset
    lcd.print(" STM32F103C8"); // Print text
    lastLcdUpdate = currentMillis; // Update last LCD update time
  }
}

