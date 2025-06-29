// === Joseph Lane ====
// Module #4 project

// Define some labels
const int red_LED1 = 14; // The red LED1 is wired to ESP32 board pin GPIO14
const int yellow_LED1 =12; // The yellow LED1 is wired to ESP32 board pin GPIO12
const int green_LED1 = 13; // The green LED1 is wired to ESP32 board pin GPIO13
const int red_LED2 = 25; // The red LED2 is wired to Mega board pin GPIO25
const int yellow_LED2 = 26; // The yellow LED2 is wired to Mega board pin GPIO 26
const int green_LED2 = 27; // The green LED2 is wired to Mega board pin GPIO 27

// the setup function runs once when you press reset or power the board
void setup() {
pinMode(red_LED1, OUTPUT); // initialize digital pin GPIO14 (Red LED1) as an output.
pinMode(yellow_LED1, OUTPUT); // initialize digital pin GPIO12 (yellow LED1) as an output.
pinMode(green_LED1, OUTPUT); // initialize digital pin GPIO13 (green LED1) as an output.
pinMode(red_LED2, OUTPUT); // initialize digital pin GPIO25(Red LED2) as an output.
pinMode(yellow_LED2, OUTPUT); // initialize digital pin GPIO26 (yellow LED2) as an output.
pinMode(green_LED2, OUTPUT); // initialize digital pin GPIO27 (green LED2) as an output.
}

// the loop function runs over and over again forever
void loop() {

// The next three lines of code turn on the red LED1
digitalWrite(red_LED1, HIGH); // This should turn on the RED LED1
digitalWrite(yellow_LED1 , LOW); // This should turn off the YELLOW LED1
digitalWrite(green_LED1, LOW); // This should turn off the GREEN LED1

delay(1000); //Extended time for Red light#1 before the Green of the other side turns ON

// The next three lines of code turn on the green LED2 for 2 seconds
digitalWrite(red_LED2, LOW); // This should turn off the RED LED2
digitalWrite(yellow_LED2 , LOW); // This should turn off the YELLOW LED2
digitalWrite(green_LED2, HIGH); // This should turn on the GREEN LED2

delay(2000); // wait for 2 seconds

// The next three lines of code turn on the red LED1
digitalWrite(red_LED1, HIGH); // This should turn on the RED LED1
digitalWrite(yellow_LED1 , LOW); // This should turn off the YELLOW LED1
digitalWrite(green_LED1, LOW); // This should turn off the GREEN LED1

// The next three lines of code turn on the yellow LED2
digitalWrite(red_LED2, LOW); // This should turn off the RED LED2
digitalWrite(yellow_LED2 , HIGH); // This should turn on the YELLOW LED2
digitalWrite(green_LED2, LOW); // This should turn off the GREEN LED2

delay(2000); // wait for 2 seconds

// The next three lines of code turn on the red LED2
digitalWrite(red_LED2, HIGH); // This should turn on the RED LED2
digitalWrite(yellow_LED2 , LOW); // This should turn off the YELLOW LED2
digitalWrite(green_LED2, LOW); // This should turn off the GREEN LED2

delay(1000); //Extended time for Red light#2 before the Green of the other side turns ON

// The next three lines of code turn on the green LED1
digitalWrite(red_LED1, LOW); // This should turn off the RED LED1
digitalWrite(yellow_LED1 , LOW); // This should turn off the YELLOW LED1
digitalWrite(green_LED1, HIGH); // This should turn on the GREEN LED1

delay(2000); // wait for 1 second

// The next three lines of code turn on the yellow LED1
digitalWrite(red_LED1, LOW); // This should turn off the RED LED1
digitalWrite(yellow_LED1 , HIGH); // This should turn on the YELLOW LED1
digitalWrite(green_LED1, LOW); // This should turn off the GREEN LED1

// The next three lines of code turn on the red LED2
digitalWrite(red_LED2, HIGH); // This should turn on the RED LED2
digitalWrite(yellow_LED2 , LOW); // This should turn off the YELLOW LED2
digitalWrite(green_LED2, LOW); // This should turn off the GREEN LED2

delay(2000); // wait for 1 second

}