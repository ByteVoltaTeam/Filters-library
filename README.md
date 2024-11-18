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
