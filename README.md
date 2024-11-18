# Filters Library for Arduino

A collection of noise-filtering algorithms implemented for Arduino, including **Moving Average**, **Kalman Filter**, **Low-Pass**, **High-Pass**, and **Threshold filters**. This library provides an easy way to smooth sensor data, reduce noise, and process signals effectively in Arduino projects.

## Features

- **Moving Average Filter**: Smooths data by averaging over a sliding window of values.
- **Kalman Filter**: A powerful filter for sensor data fusion, useful for estimating a system's state by minimizing the variance of the errors.
- **Low-Pass Filter**: Smooths out high-frequency noise and allows low-frequency signals to pass through.
- **High-Pass Filter**: Removes low-frequency noise and allows high-frequency signals to pass.
- **Threshold Filter**: Simple filter to detect whether a value exceeds a specified threshold.

## Installation

1. **Download the library**: 
   - You can either clone this repository or download it as a ZIP file and add it to your Arduino libraries.

   To clone via Git, run the following command in your Arduino sketchbook's `libraries` folder:
   ```bash
   git clone https://github.com/your-username/Filters.git
