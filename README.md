# asm-planB_arduino

<<<<<<< HEAD
Summary;

Hardware:
 - Dual MC33926 Motor Driver Carrier; 
   - link: https://www.pololu.com/product/1213
=======
# Summary
This file acts as the backup program for RASMv2

# Hardware
-3 Dual MC33926 Motor Driver Carrier (motor shield);
 - link: https://www.pololu.com/product/1213
- Arduino Mega 2560 R3
- Motors; [need to add later]

# Arduino Library
- DualMC33926Motor3Shield
  * only default pins, current version does not allow for pin mapping. (except by changing the pins in .cpp file)
  * setM#Speed(int speed); - to set speed for motor #
  * getM#CurrentMilliamps(); - read current reading from Motor #
  ** this library does not have brake function (setM#Brake) like in DualVN5019MotorShield Library
 
- Encoder
  
  ## Example Program
---------------
# 1. Demo.
 Demo 1.
 * For testing the custom motor library "DualMC33926Motor3Shield" and check if the library works as intended
 
 Demo 2.
 * Testing the motors and encoder reading value. 
 * library: Encoder.h && DualMC33926Motor3Shield
