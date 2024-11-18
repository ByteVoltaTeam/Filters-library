Filters Library for Arduino
A collection of noise-filtering algorithms implemented for Arduino, including Moving Average, Kalman Filter, Low-Pass, High-Pass, and Threshold filters. This library provides an easy way to smooth sensor data, reduce noise, and process signals effectively in Arduino projects.

Features
Moving Average Filter: Smooths data by averaging over a sliding window of values.
Kalman Filter: A powerful filter for sensor data fusion, useful for estimating a system's state by minimizing the variance of the errors.
Low-Pass Filter: Smooths out high-frequency noise and allows low-frequency signals to pass through.
High-Pass Filter: Removes low-frequency noise and allows high-frequency signals to pass.
Threshold Filter: Simple filter to detect whether a value exceeds a specified threshold.
Installation
Download the library:

You can either clone this repository or download it as a ZIP file and add it to your Arduino libraries.
To clone via Git, run the following command in your Arduino sketchbook's libraries folder:

bash
Copiar código
git clone https://github.com/your-username/Filters.git
To install via ZIP:

Download the ZIP from this repository.
Open the Arduino IDE, go to Sketch -> Include Library -> Add .ZIP Library, and select the downloaded ZIP file.
Include the library in your sketch:

cpp
Copiar código
#include <Filters.h>
Usage
1. Moving Average Filter
The moving average filter smooths your data by averaging over a defined number of previous readings (a window size).

cpp
Copiar código
Filters Filters;  // Create an instance of the Filters class

#define WINDOW_SIZE 10  // Define the size of the window for the moving average filter

void setup() {
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  int sensorValue = analogRead(A0);  // Read the sensor value
  float smoothedValue = Filters.movingAverage(sensorValue, WINDOW_SIZE);  // Apply moving average filter

  Serial.println(smoothedValue);  // Print the smoothed value
  delay(100);
}
2. Kalman Filter
The Kalman filter is useful for estimating the true state of a noisy system. It takes into account the uncertainty of both the process and the measurement noise.

cpp
Copiar código
#define processNoise 0.03
#define measurementNoise 0.001
#define estimateError 0.1
#define initialEstimate 1.0

void setup() {
  Serial.begin(9600);
  Filters.setKalman(processNoise, measurementNoise, estimateError, initialEstimate);  // Initialize Kalman filter
}

void loop() {
  float measurement = analogRead(A0);  // Read sensor value
  float filteredValue = Filters.kalman1D(measurement);  // Apply Kalman filter

  Serial.println(filteredValue);  // Print the filtered value
  delay(100);
}
3. Low-Pass and High-Pass Filters
Use low-pass and high-pass filters to remove high-frequency or low-frequency noise, respectively.

cpp
Copiar código
#define alpha 0.01  // Filter smoothing factor

float lastMeasurement = 0.0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float measurement = analogRead(A0);  // Read sensor value
  float lowPassValue = Filters.lowPass(measurement, alpha, lastMeasurement);  // Apply low-pass filter
  float highPassValue = Filters.highPass(measurement, alpha, lastMeasurement);  // Apply high-pass filter

  Serial.print("Low-Pass: ");
  Serial.print(lowPassValue);
  Serial.print("\tHigh-Pass: ");
  Serial.println(highPassValue);

  lastMeasurement = measurement;
  delay(100);
}
4. Threshold Filter
This simple filter checks whether a value exceeds a defined threshold.

cpp
Copiar código
#define threshold 100.0  // Define threshold value

void setup() {
  Serial.begin(9600);
}

void loop() {
  float measurement = analogRead(A0);  // Read sensor value
  bool isAboveThreshold = Filters.thresholdFilter(measurement, threshold);  // Check threshold

  if (isAboveThreshold) {
    Serial.println("Value exceeds threshold!");
  } else {
    Serial.println("Value is below threshold.");
  }

  delay(100);
}
API
Methods Available
Filters.setKalman(processNoise, measurementNoise, estimateError, initialEstimate)

Initializes the Kalman filter with the specified parameters.
Parameters:
processNoise: Process noise covariance (Q)
measurementNoise: Measurement noise covariance (R)
estimateError: Initial estimate error covariance (P)
initialEstimate: Initial state estimate (x)
float Filters.movingAverage(int newReading, uint16_t size)

Computes the moving average with a sliding window of size size.
Parameters:
newReading: The new data point.
size: The size of the window (buffer size).
Returns: The computed moving average.
float Filters.lowPass(float newRead, float alpha, float lastRead)

Applies a low-pass filter (smoothing) on the signal.
Parameters:
newRead: The new sensor reading.
alpha: The filter coefficient (typically between 0 and 1).
lastRead: The previous filtered reading.
Returns: The filtered value.
float Filters.highPass(float newRead, float alpha, float lastRead)

Applies a high-pass filter to remove low-frequency noise.
Parameters:
newRead: The new sensor reading.
alpha: The filter coefficient (typically between 0 and 1).
lastRead: The previous filtered reading.
Returns: The filtered value.
bool Filters.thresholdFilter(float newReading, float threshold)

Checks if the newReading exceeds the defined threshold.
Parameters:
newReading: The new sensor reading.
threshold: The threshold value.
Returns: true if the value exceeds the threshold, otherwise false.
float Filters.kalman1D(float measurement)

Applies the Kalman filter to the given measurement.
Parameters:
measurement: The current sensor reading.
Returns: The filtered value.
Example Project
You can find a complete example in the examples/ folder of this repository. It demonstrates how to use the different filters in a real-world project.

Contributing
If you would like to contribute to this library, feel free to fork the repository and submit a pull request. Here are some ways you can help:

Report any bugs or issues you find.
Suggest new features or improvements.
Submit fixes or enhancements.
License
This library is released under the MIT License.

