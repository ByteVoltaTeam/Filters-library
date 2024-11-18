# Filters Library for Arduino

A versatile filtering library for Arduino that provides a set of tools for signal processing, including moving average, low-pass, high-pass, threshold, and Kalman filters.

---

## Features

- **Moving Average Filter**: Smoothens input signals by averaging a dynamic-sized buffer.
- **Low-Pass Filter**: Removes high-frequency noise from signals.
- **High-Pass Filter**: Highlights rapid changes in signals.
- **Threshold Filter**: Detects values exceeding a specified threshold.
- **Kalman Filter**: Provides an optimal estimate for noisy 1D measurements.

---

## Installation

1. Clone or download this repository:
   ```bash
   git clone https://github.com/your_username/Filters.git
   ```
   
2. Copy the Filters folder into the libraries folder of your Arduino installation directory:
   ```bash
      Arduino/libraries/
   ```
4. Restart the Arduino IDE for the library to be recognized.

## Usage

Include the library in your Arduino sketch:
   ```bash
       #include <Filters.h>
   ```

Create an instance of the Filters class:
   ```bash
      Filters filter;
   ```

## Examples

### Moving Average
   
   ```bash
      int sensorReading = analogRead(A0);
      float average = filter.movingAverage(sensorReading, 10); // 10-element buffer
   ```

### Low-Pass Filter
    
   ```bash
      float smoothedValue = filter.lowPass(newReading, 0.1, lastReading);
   ```

### High-Pass Filter

   ```bash
      float filteredValue = filter.highPass(newReading, 0.1, lastReading);
   ```

### Threshold Filter

   ```bash
      if (filter.thresholdFilter(sensorReading, 500)) {
        // Do something if threshold exceeded
      }
   ```

### Kalman Filter
    
   ```bash
      filter.setKalman(0.01, 1, 0.1, 0); // Initialize Kalman parameters
      float filteredValue = filter.kalman1D(sensorReading);
   ```

## API Reference

### Moving Average
- **`movingAverage(int newReading, uint16_t size)`**  
  Calculates the moving average of the input values using a buffer of dynamic size.  

- **`clearBuffer()`**  
  Clears the moving average buffer.

### Low-Pass Filter
- **`lowPass(float newRead, float alpha, float lastRead)`**  
  Applies a low-pass filter to smooth input values.

### High-Pass Filter
- **`highPass(float newRead, float alpha, float lastRead)`**  
  Applies a high-pass filter to emphasize rapid changes in input values.

### Threshold Filter
- **`thresholdFilter(float newReading, float threshold)`**  
  Returns `true` if the input value exceeds the specified threshold.

### Kalman Filter
- **`setKalman(float processNoise, float measurementNoise, float estimateError, float initialEstimate)`**  
  Configures the Kalman filter with custom parameters.

- **`kalman1D(float measurement)`**  
  Applies a 1D Kalman filter to the input measurement and returns the filtered value.

---

## Contributing

Contributions are welcome! If you have suggestions for improvements or new features, feel free to open an issue or submit a pull request.

To contribute:  
1. Fork the repository.  
2. Create a new branch for your feature or bug fix: `git checkout -b feature-name`  
3. Make your changes and commit them: `git commit -m "Description of your changes"`  
4. Push to your forked repository: `git push origin feature-name`  
5. Open a pull request in the original repository.

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

---

## Acknowledgments

Special thanks to the Arduino community and all contributors for their support and inspiration.

---

## Contact

For any questions or feedback, feel free to reach out via [GitHub Issues](https://github.com/ByteVoltaTeam/Filters/issues).
