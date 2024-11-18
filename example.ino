/*
MIT License

Copyright (c) 2024 João P. V. Silveira

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <Filters.h>

// Create an instance of the Filters class
Filters Filters;

// Kalman Filter parameters
#define processNoise 0.03
#define measurementNoise 0.001
#define estimateError 0.1
#define initialEstimate 1.0

// Low-pass / High-pass filter alpha value
#define alpha 0.01

// Window size for the moving average filter
#define WINDOW_SIZE 10

// Last measurement for high-pass/low-pass filters
float lastmeasurement = 0.0;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set the Kalman filter parameters
  Filters.setKalman(processNoise, measurementNoise, estimateError, initialEstimate);

  // Print header for better visibility in the serial monitor
  Serial.println("Output of various filters:");
  Serial.println("---------------------------------------------------");
  Serial.println("High-Pass\tLow-Pass\tKalman\tMoving Average");
  Serial.println("---------------------------------------------------");
}

void loop() {
  // Read the sensor value from analog pin A0
  float measurement = analogRead(A0);

  // Apply High-Pass and Low-Pass filters
  float out1 = Filters.highPass(measurement, alpha, lastmeasurement);
  float out2 = Filters.lowPass(measurement, alpha, lastmeasurement);

  // Apply the Kalman filter
  float out3 = Filters.kalman1D(measurement);

  // Apply the Moving Average filter
  float out4 = Filters.movingAverage(measurement, WINDOW_SIZE);

  // Update the last measurement for future use
  lastmeasurement = measurement;

  // Print the results in a readable format
  Serial.print(out1, 3);  // Print with 3 decimal places
  Serial.print("\t\t");
  Serial.print(out2, 3);  // Print with 3 decimal places
  Serial.print("\t\t");
  Serial.print(out3, 3);  // Print with 3 decimal places
  Serial.print("\t\t");
  Serial.println(out4, 3);  // Print with 3 decimal places

  // Delay for stability (optional)
  delay(100);
}
