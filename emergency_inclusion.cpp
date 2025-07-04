// === Joseph Lane ====
// Module #6 project #include <Wire.h> //lcd
#include <LiquidCrystal_I2C.h> //lcd

LiquidCrystal_I2C lcd(0x27,16,2); //set the LCD address to 0x3F for a 16 chars and 2-line display
// if it does not work then try 0x3F, if both addresses do not work then run the scan code below

const int bzr=32; // GPIO32 to connect the Buzzer
//==================== LCD ====================
const int red_LED1 = 14;  // The red LED1 is wired to ESP32 board pin GPIO14
const int yellow_LED1 =12;  // The yellow LED1 is wired to ESP32 board pin GPIO12
const int green_LED1 = 13; // The green LED1 is wired to ESP32 board pin GPIO13
const int red_LED2 = 25;  // The red LED2 is wired to Mega board pin GPIO25
const int yellow_LED2 = 26; // The yellow LED2 is wired to Mega board pin GPIO 26
const int green_LED2 = 27; // The green LED2 is wired to Mega board pin GPIO 27

int Xw_value;
const int Xw_button = 19; //Cross Walk button

void setup() 
{
  
Serial.begin(115200);
pinMode(Xw_button, INPUT_PULLUP); // 0=pressed, 1 = unpressed button

lcd.init(); // initialize the lcd lcd.backlight();
lcd.setCursor(0,0); // column#4 and Row #1 
lcd.print(" === CEIS114 ===");
pinMode(bzr,OUTPUT);

pinMode(red_LED1, OUTPUT); // initialize digital pin 14 (Red LED1) as an output.
pinMode(yellow_LED1, OUTPUT); // initialize digital pin12 (yellow LED1) as an output.
pinMode(green_LED1, OUTPUT);  // initialize digital pin 13 (green LED1) as an output.

pinMode(red_LED2, OUTPUT); // initialize digital pin 25(Red LED2) as an output.
pinMode(yellow_LED2, OUTPUT); // initialize digital pin 26 (yellow LED2) as an output.
pinMode(green_LED2, OUTPUT); // initialize digital pin 27 (green LED2) as an output.

}

// the loop function runs over and over again forever 
void loop() 
{

// read the cross walk button value: 
Xw_value=digitalRead(Xw_button);

if (Xw_value == LOW ){ // if crosswalk button (X-button) pressed
digitalWrite(yellow_LED1 , LOW);  // This should turn off the YELLOW LED1
digitalWrite(green_LED1, LOW);  // This should turn off the GREEN LED1 
digitalWrite(yellow_LED2 , LOW); // This should turn off the YELLOW LED2 
digitalWrite(green_LED2, LOW); // This should turn off the GREEN LED2

for (int i=10; i>= 0; i--)
{
Serial.print(" Count = "); 
Serial.print(i);
Serial.println(" == Walk == ");
lcd.setCursor(0,1); // set the cursor to column 1, line 2
//    lcd.clear();  // clears the display to print new message 
lcd.print("   ");
lcd.setCursor(0,1); // set the cursor to column 1, line 2 
lcd.print(" == Walk ==  "); //  Walk  characters to the LCD.
 
lcd.print(i); // Print the count to the LCD

digitalWrite(red_LED1, HIGH); // This should turn on the RED LED1 
digitalWrite(red_LED2, HIGH);   // This should turn on the RED LED2 digitalWrite(bzr, HIGH);
delay(500);
digitalWrite(red_LED1, LOW);  // This should turn off the RED LED1 
digitalWrite(red_LED2, LOW);    // This should turn off the RED LED2 digitalWrite(bzr, LOW);
delay(500);
} // End of counter
// clears the display to print new message
// ===== lcd.clear();
lcd.setCursor(0,1); // set the cursor to column 1, line 2 
lcd.print(" ");
} //

else // No Emergency ===
{
lcd.setCursor(0,1); // set the cursor to column 1, line 2
lcd.print(" = Do Not Walk ="); // Do Not Walk characters to the LCD.

Serial.println(" == Do Not Walk == ");
// The next three lines of code turn on the red LED1 
digitalWrite(red_LED1, HIGH); // This should turn on the RED LED1
 
digitalWrite(yellow_LED1 , LOW);  // This should turn off the YELLOW LED1
digitalWrite(green_LED1, LOW);  // This should turn off the GREEN LED1

delay(1000); //Extended time for Red light#1 before the Green of the other side turns 

// The next three lines of code turn on the red LED2 
digitalWrite(red_LED2, LOW);  // This should turn off the RED LED2
digitalWrite(yellow_LED2 , LOW); // This should turn off the YELLOW LED2 
digitalWrite(green_LED2, HIGH); // This should turn on the GREEN LED2

delay(2000);  // wait for 1 second

// The next three lines of code turn on the red LED1 
digitalWrite(red_LED1, HIGH); // This should turn on the RED LED1
digitalWrite(yellow_LED1 , LOW);  // This should turn off the YELLOW LED1
digitalWrite(green_LED1, LOW);  // This should turn off the GREEN LED1

// The next three lines of code turn on the red LED2 
digitalWrite(red_LED2, LOW);  // This should turn on the RED LED2
digitalWrite(yellow_LED2 , HIGH); // This should turn off the YELLOW LED2 
digitalWrite(green_LED2, LOW);  // This should turn off the GREEN LED2 
delay(2000);  // wait for 1 second
 
// The next three lines of code turn on the red LED2
digitalWrite(red_LED2, HIGH);   // This should turn on the RED LED2 
digitalWrite(yellow_LED2 , LOW); // This should turn off the YELLOW LED2 
digitalWrite(green_LED2, LOW);  // This should turn off the GREEN LED2

delay(1000); //Extended time for Red light#2 before the Green of the other side turns 

// The next three lines of code turn on the yellow LED1
digitalWrite(red_LED1, LOW);  // This should turn off the RED LED1
digitalWrite(yellow_LED1 , LOW);  // This should turn off the YELLOW LED1
digitalWrite(green_LED1, HIGH); // This should turn off the GREEN LED1

delay(2000);  // wait for 1 second

// The next three lines of code turn on the yellow LED1
digitalWrite(red_LED1, LOW);  // This should turn off the RED LED1
digitalWrite(yellow_LED1 , HIGH); // This should turn on the YELLOW LED1
digitalWrite(green_LED1, LOW);  // This should turn off the GREEN LED1

// The next three lines of code turn on the red LED2
digitalWrite(red_LED2, HIGH); // This should turn on the RED LED2 
digitalWrite(yellow_LED2 , LOW); // This should turn off the YELLOW LED2
digitalWrite(green_LED2, LOW);  // This should turn off the GREEN LED2 
delay(2000);  // wait for 1 second

}// Emergency Button closing ============

}