# asm-planB_arduino
=======
# Summary
This file acts as the backup program for RASMv2 main control program

# Hardware
## Motor Driver
-3 Dual MC33926 Motor Driver Carrier (motor shield);
 - link: https://www.pololu.com/product/1213
 - Arduino Mega 2560 R3
  - Motor shield pins (functions and their pins requirements);
  * nD2 (digital); tristate disables both outputs of both motor channels when LOW; toggling resets latched driver fault condition
  * M1DIR and M2DIR (digital); motor 1 and motor 2 direction input
  * M1PWM and M2PWM (digital PWM); motor 1 and motor 2 speed
  * M1FB and M2FB (analog); motor 1 and motor 2 current sense output, approc 525mV/A
  * nSF (digital); status flag indicator

## Motor Selection
- 5 Motors; [need to add later]

- Filtering Motor Noise
  * Using *RealTimeLTIFilter* in signal_processing.hpp (link: https://github.com/ASM-Advised-Projects/rasm-v2/blob/master/include/control/signal_processing.hpp)
  * other choices: low pass filter if necessary
  
## Encoders;
   * Encoders from: 
   * Encoders pins (connected to digital pins arduino, reccommended interrupt pins 2,3,18,19,20,21);
    - encoder motor 1: pins 2,3
    - encoder motor 2: pins 18,19
    - encoder motor 3: pins 20,21
    - encoder motor 4: pins D#, D# 
    - encoder motor 5: pins D#, D#
    
# Arduino Library
* DualMC33926Motor3Shield; 
 - supports 3 DualMC33926 motor shields, if needs to change any motor driver-arduino pins, change it in the .cpp file.
  
  
  # Example Program
---------------
## 1. Demo.
 ### Demo 1.
 * For testing the custom motor library "DualMC33926Motor3Shield" and check if the library works as intended
 
 ### Demo 2.
 * Testing the motors and encoder reading value. 
 * library: Encoder.h && DualMC33926Motor3Shield

 ### Demo 3.
 * Refine encoder reading values by using filters- software and electronics(if necessary)
