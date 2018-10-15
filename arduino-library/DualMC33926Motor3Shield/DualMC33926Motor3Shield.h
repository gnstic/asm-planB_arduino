// this is the header file for the Dual MC33926 Motor Sheild to incorporate 3 motor drivers on Arduino Mega for RASM project. This header file is built from [link below] as the reference

//#ifndef (__AVR_ATmega1280__) || ndef(__AVR_ATmega2560__)
//#error "This library only supports Arduino Mega boards."
//#endif

#ifndef DualMC33926Motor3Shield_h
#define DualMC33926Motor3Shield_h

#include <Arduino.h>

class DualMC33926Motor3Shield_h
{
  public:  
    // CONSTRUCTORS
	 // Default pin selection.
    DualMC33926Motor3Shield_h();

	// PUBLIC METHODS
	void init(); // Initialize TIMER 1, set the PWM to 20kHZ. 
	void setM1Speed(int speed); // Set speed for M1.
	void setM2Speed(int speed); // Set speed for M2.
	void setM3Speed(int speed);
	void setM4Speed(int speed);
	void setM5Speed(int speed);
	void setM6Speed(int speed);

	void setSpeeds(int m1Speed, int m2Speed, int M3Speed, int M4Speed, int M5Speed, int M6Speed); // Set speed for both M1 and M2.

	unsigned int getM1CurrentMilliamps(); // Get current reading for M1. 
	unsigned int getM2CurrentMilliamps(); // Get current reading for M2.
	unsigned int getM3CurrentMilliamps();
	unsigned int getM4CurrentMilliamps();
	unsigned int getM5CurrentMilliamps();
	unsigned int getM6CurrentMilliamps();



	unsigned char getFault(); // Get fault reading.
   
private:

	unsigned char _nD2;
	unsigned char _M1DIR;
	unsigned char _M2DIR;
	unsigned char _M1PWM;
	unsigned char _M2PWM;
	unsigned char _nSF;
	unsigned char _M1FB;
	unsigned char _M2FB;

	unsigned char _nD22;
	unsigned char _M3DIR;
	unsigned char _M4DIR;
	unsigned char _M3PWM;
	unsigned char _M4PWM;
	unsigned char _nSF2;
	unsigned char _M3FB;
	unsigned char _M4FB;

	unsigned char _nD23;
	unsigned char _M5DIR;
	unsigned char _M6DIR;
	unsigned char _M5PWM;
	unsigned char _M6PWM;
	unsigned char _nSF3;
	unsigned char _M5FB;
	unsigned char _M6FB;
}; //end of class
#endif
