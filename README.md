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
- for the time being, still study the DualVNH5019MotorShieldMod3, a custom arduino library created by https://github.com/photodude/DualVNH5019MotorShieldMod3 , but library is for Dual VNH5019 Motor Shield. Still study if the library can be used on other type of motor shield.
- Using the Arduino IDE;
  - In the Arduino IDE, open the "Sketch" menu, select "Include Library", then "Manage Libraries...".
  - Search for "DualVNH5019MotorShieldMod3".
  - Click the DualVNH5019MotorShieldMod3 entry in the list.
  - Click "Install"
  
  ## Example Program
---------------
# 1. Demo.
 Demo 1.
 * For testing the custom motor library "DualMC33926Motor3Shield" and check if the library works as intended
 
 Demo 2.
 * Testing the motors and encoder reading value. 
 * library: Encoder.h && DualMC33926Motor3Shield
