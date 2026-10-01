# STM32C0 Bare-Metal Dual LED Toggle

A simple **STM32C0 bare-metal firmware project** that uses a push button to alternate between two LEDs. The project demonstrates direct register-level GPIO configuration using CMSIS without STM32 HAL.

### Hardware

* **MCU:** STM32C0 Series
* **LED 1:** PC13
* **LED 2:** PC14
* **Push Button:** PA0 with internal pull-up

### How It Works

* Button is configured as an input with an internal pull-up.
* A **HIGH → LOW transition** detects a button press.
* Each press toggles the active LED:

  * Press 1 → LED 1 ON, LED 2 OFF
  * Press 2 → LED 1 OFF, LED 2 ON
* GPIO is configured directly through `MODER`, `PUPDR`, `IDR`, and `ODR` registers.
* A simple software delay is used for button debouncing and timing.

### Key Concepts

* Embedded C
* STM32C0 / ARM Cortex-M0+
* Bare-Metal Programming
* CMSIS
* Memory-Mapped Registers
* GPIO Configuration
* Pull-Up Input
* Button Edge Detection
* Bitwise Operations
* Software Debouncing

### Simulation

WOWKI LINK: https://wokwi.com/projects/476672277483252737

### Files

```text
main.c
README.md
```
