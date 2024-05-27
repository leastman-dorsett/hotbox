#include <Arduino.h>
#include <Adafruit_MAX31865.h>
#include <SPI.h>

// Define the Chip Select (CS) pin for the MAX31865
#define MAX31865_CS 17

// Create an instance of the sensor using hardware SPI
Adafruit_MAX31865 max31865 = Adafruit_MAX31865(MAX31865_CS);

// The value of the Rref resistor. Use 430.0 if using the Adafruit PT100 breakout board.
#define RREF 430.0
// Set the number of wires in the PT100 sensor (2, 3, or 4)
#define WIRE_COUNT 3  // Change this to 2 if you are using a 2-wire sensor

void setup() {
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);
  Serial.println("Adafruit MAX31865 PT100 Sensor Test!");

  // Initialize the MAX31865 sensor
  if (!max31865.begin(MAX31865_3WIRE)) {  // Use MAX31865_2WIRE for a 2-wire sensor
    Serial.println("Failed to initialize MAX31865. Please check your connections.");
    while (1);
  }
}

void loop() {
  // Read the temperature from the sensor
  float temperature = max31865.temperature(100, RREF);

  // Print the temperature to the serial monitor
  Serial.print("Temperature: "); 
  Serial.println(temperature * (9.0/5.0) + 32);

  // Delay for 1 second before the next reading
  delay(1000);
}