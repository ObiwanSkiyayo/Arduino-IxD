/*Setup the MQ-2 GAS Sensor with output to Serial Monitor
 * Suitable to detect LPG, Butane, Propane, Methane, Alchohol, Hydrogen and Smoke.
 * Product link: https://www.hackerstore.nl/Artikel/704
*/

#include <Arduino.h>
#include <TM1637Display.h>

// MQ-2 GAS Sensor connection pins (Analog Pins)
int gasPin = A0;

// Display connection pins (Digital Pins)
#define CLK 2
#define DIO 3

// Display connection Setup
TM1637Display display(CLK, DIO);

void setup() {

  // Initilizing the Serial Port - 9600
  pinMode(gasPin, INPUT);
  Serial.begin(9600);


  // Initilizing the Display
  display.setBrightness(10);
  uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 };
  display.setSegments(data);

}

void loop() {

  Serial.println(analogRead(gasPin)); // Get data from the analog pin.
  display.showNumberDec(analogRead(gasPin), false); // Show gasPin data on the Display
  delay(1000); // Print the value every second.

}
