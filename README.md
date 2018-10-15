# asm-planB_arduino

<<<<<<< HEAD
Summary;

Hardware:
 - 3 Dual MC33926 Motor Driver Carrier; 
   - link: https://www.pololu.com/product/1213
   - Motor shield pins (functions and their pins requirements);
    * nD2 (digital); tristate disables both outputs of both motor channels when LOW; toggling resets latched driver fault condition
    * M1DIR and M2DIR (digital); motor 1 and motor 2 direction input
    * M1PWM and M2PWM (digital PWM); motor 1 and motor 2 speed
    * M1FB and M2FB (analog); motor 1 and motor 2 current sense output, approc 525mV/A
    * nSF (digital); status flag indicator
=======
# Summary
This file acts as the backup program for RASMv2 main control program

# Hardware
-3 Dual MC33926 Motor Driver Carrier (motor shield);
 - link: https://www.pololu.com/product/1213
- Arduino Mega 2560 R3
- 6 Motors; [need to add later]

# Arduino Library
* DualMC33926Motor3Shield; 
 - supports 3 DualMC33926 motor shields, if needs to change any motor driver-arduino pins, change it in the .cpp file.
  
  
  ## Example Program
---------------
# 1. Demo.
 Demo 1.
 * For testing the custom motor library "DualMC33926Motor3Shield" and check if the library works as intended
 
 Demo 2.
 * Testing the motors and encoder reading value. 
 * library: Encoder.h && DualMC33926Motor3Shield
