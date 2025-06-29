// === Joseph Lane ====
// Module #3 project

const int red_LED1 = 14;  // The red LED1 is wired to ESP32 board pin GPIO14 
const int yellow_LED1 = 12;   // The yellow LED1 is wired to ESP32 board pin GPIO12 
const int green_LED1 = 13; // The green LED1 is wired to ESP32 board pin GPIO13

// the setup function runs once when you press reset or power the board 
void setup() 
{
pinMode(red_LED1, OUTPUT);  // initialize digital pin GPIO14 (Red LED1) as an output.
pinMode(yellow_LED1, OUTPUT); // initialize digital pin GPIO12 (yellow LED1) as an output.
pinMode(green_LED1, OUTPUT);  // initialize digital pin GPIO13 (green LED1) as an output.
}

// the loop function runs over and over again forever 
void loop() {
// The next three lines of code turn on the red LED1 
digitalWrite(red_LED1, HIGH); // This should turn on the RED LED1
digitalWrite(yellow_LED1 , LOW);   // This should turn off the YELLOW LED1 
digitalWrite(green_LED1, LOW);  // This should turn off the GREEN LED1

delay(2000);  // wait for 2 seconds

// The next three lines of code turn on the green LED1 
digitalWrite(red_LED1, LOW);  // This should turn off the RED LED1
 
digitalWrite(yellow_LED1 , LOW);    // This should turn off the YELLOW LED1 
digitalWrite(green_LED1, HIGH); // This should turn on the GREEN LED1

delay(2000);  // wait for 2 seconds

// The next three lines of code turn on the yellow LED1 
digitalWrite(red_LED1, LOW);  // This should turn off the RED LED1
digitalWrite(yellow_LED1 , HIGH); // This should turn on the YELLOW LED1 
digitalWrite(green_LED1, LOW);  // This should turn off the GREEN LED1

delay(2000);  // wait for 2 seconds
}