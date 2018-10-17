// this is the header file for the Dual MC33926 Motor Sheild to incorporate 3 motor drivers on Arduino Mega for RASM project. This header file is built from [link below] as the reference
#pragma once

#ifndef dualMC33926_motorDriver1_h
#define dualMC33926_motorDriver1_h

#include <Arduino.h>

class dualMC33926_motorDriver1
{
	public:
		// CONSTRUCTORS
		 // Default pin selection.
		dualMC33926_motorDriver1();

		// PUBLIC METHODS
		void init(); // Initialize TIMER 1, set the PWM to 20kHZ.
		void setM1Speed(int speed); // Set speed for M1.
		void setM2Speed(int speed); // Set speed for M2.
		void setSpeeds(int m1Speed, int m2Speed); // Set speed for both M1 and M2.

		unsigned int getM1CurrentMilliamps(); // Get current reading for M1.
		unsigned int getM2CurrentMilliamps(); // Get current reading for M2.

		unsigned char getFault(); // Get fault reading.

	private:
		unsigned char _M1IN1;
		unsigned char _M1IN2;
		unsigned char _M1PWM_D1;
		unsigned char _M1SF;
		unsigned char _M1FB;
		unsigned char _EN1;
		unsigned char _M2IN1;
		unsigned char _M2IN2;
		unsigned char _M2PWM_D1;
		unsigned char _M2SF;
		unsigned char _M2FB;

}; //end of class
#endif
