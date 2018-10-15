/* This is the motor shield library that will be used on RASM. The library is for Pololu Dual MC 33926 motor shield. The RASM will use 3 motor shields, that will connect to 5 DC motors*/

// include DualMC33926 header file
//#include "Arduino.h"
#include "DualMC33926Motor3Shield.h"


// Constructors ////////////////////////////////////////////////////////////////

// default pins for the library, and for the time being this library only supports default pins connections
DualMC33926Motor3Shield::DualMC33926Motor3Shield()
{
  //Default Pin Map for motor shield 1
  _nD2 = 4;		// tri-state disable both outputs of both motor channels when LOW, toggling resets latched driver fault condition
  _M1DIR = 7;	// motor 1 direction 
  _M1PWM = 9;	// motor 1 speed (digital PWM)
  _M2DIR = 8;	// motor 2 direction
  _M2PWM = 10;	// motor 2 speed (digital PWM)	
  _nSF = 12;	// status flag indicator (LOW indicates fault)
  _M1FB =A0;	//analog 0; motor 1 current sense output (525mV/A)
  _M2FB =A1;	// analog 1; motor 2 current sense output (525mV/A)
  _M3FB =A8;	//analog 8; motor 3 current 
  _M4FB =A9;	//analog 9; motor 4 current
  _M5FB =A11;	//analog 11; motor 3 current 
  _M6FB =A10;	//analog 10; motor 4 current

  // Default Pin Map for motor shield 2;  the 
  _nD22 = 26;	// ND pin for motor shield 2[unsure]
  _M3DIR = 25;	// motor 3 direction	
  _M3PWM = 5;	// motor 3 speed (digital PWM)
  _M4DIR = 24;	// motor 4 direction
  _M4PWM = 6;	// motor 4 speed (digital PWM)
  _nSF2 = 22;	//Status Flag for motor shield 2 [unsure]
 // _M3FB = A8;	//analog 8; motor 3 current 
 // _M4FB = A9;	//analog 9; motor 4 current
  
  // Default Pin Map for motor shield 3 [will udpate later]
  _nD23 = 46;	// ND pin for motor shield 2[unsure]
  _M5DIR = 47;	// motor 3 direction	
  _M5PWM = 2;	// motor 3 speed (digital PWM)
  _M6DIR = 48;	// motor 4 direction
  _M6PWM = 3;	// motor 4 speed (digital PWM)
  _nSF3 = 49;	//Status Flag for motor shield 2 [unsure]
  //_M5FB = A11;	//analog 11; motor 3 current 
  //_M6FB = A10;	//analog 10; motor 4 current
}

// Public Methods //////////////////////////////////////////////////////////////
void DualMC33926Motor3Shield::init()
{
// Define pinMode for the pins and set the frequency for timer1.
	// intialization for motor shield 1
  pinMode(_M1DIR,OUTPUT);
  pinMode(_M1PWM,OUTPUT);
  pinMode(_M1FB,INPUT);
  pinMode(_M2DIR,OUTPUT);
  pinMode(_M2PWM,OUTPUT);
  pinMode(_M2FB,INPUT);
  pinMode(_nD2,OUTPUT);  digitalWrite(_nD2,HIGH); // default to on
  pinMode(_nSF,INPUT);

	// initialization for motor shield 2
  pinMode(_M3DIR,OUTPUT);
  pinMode(_M3PWM,OUTPUT);
  pinMode(_M3FB,INPUT);
  pinMode(_M4DIR,OUTPUT);
  pinMode(_M4PWM,OUTPUT);
  pinMode(_M4FB,INPUT);
  pinMode(_nD22,OUTPUT);  digitalWrite(_nD22,HIGH); // default to on
  pinMode(_nSF2,INPUT);	
	
	// intialization ofr motor shield 3
  pinMode(_M5DIR, OUTPUT);
  pinMode(_M5PWM, OUTPUT);
  pinMode(_M5FB, INPUT);
  pinMode(_M6DIR, OUTPUT);
  pinMode(_M6PWM, OUTPUT);
  pinMode(_M6FB, INPUT);
  pinMode(_nD23, OUTPUT);  digitalWrite(_nD23, HIGH); // default to on
  pinMode(_nSF3, INPUT);
	
  //#ifdef DUALMC33926MOTORSHIELD_TIMER1_AVAILABLE
    //if (_M1PWM == _M1PWM_TIMER1_PIN && _M2PWM == _M2PWM_TIMER1_PIN)
#if defined(__AVR_ATmega168__)|| defined(__AVR_ATmega328P__)
    {
      // Timer 1 configuration
      // prescaler: clockI/O / 1
      // outputs enabled
      // phase-correct PWM
      // top of 400
      //
      // PWM frequency calculation
      // 16MHz / 1 (prescaler) / 2 (phase-correct) / 400 (top) = 20kHz
      TCCR1A = 0b10100000;
      TCCR1B = 0b00010001;
      ICR1 = 400;
    }
#endif
} // end of public methods

/***** Setting up the speed for each motors *****/
// Set speed for motor 1, speed is a number betwenn -400 and 400
void DualMC33926Motor3Shield::setM1Speed(int speed)
{
  unsigned char reverse = 0;

  if (speed < 0)
  {
    speed = -speed;  // Make speed a positive quantity
    reverse = 1;  // Preserve the direction
  }
  if (speed > 400)  // Max PWM dutycycle
    speed = 400;

  /*The older version
  #ifdef DUALMC33926MOTORSHIELD_TIMER1_AVAILABLE
    if (_M1PWM == _M1PWM_TIMER1_PIN && _M2PWM == _M2PWM_TIMER1_PIN)
    {
      OCR1A = speed;
    }
    else
    {
      analogWrite(_M1PWM,speed * 51 / 80); // map 400 to 255
    }
  #else
    analogWrite(_M1PWM,speed * 51 / 80); // map 400 to 255
  #endif*/
	// newer version
	#if defined(__AVR_ATmega168__)|| defined(__AVR_ATmega328P__)
	  OCR1A = speed;
	#else
	  analogWrite(_M1PWM, speed * 51 / 80); // default to using analogWrite, mapping 400 to 255
	#endif
  if (reverse)
    digitalWrite(_M1DIR,HIGH);
  else
    digitalWrite(_M1DIR,LOW);
} // end of setM1Speed

// Set speed for motor 2, speed is a number betwenn -400 and 400
void DualMC33926Motor3Shield::setM2Speed(int speed)
{
  unsigned char reverse = 0;

  if (speed < 0)
  {
    speed = -speed;  // Make speed a positive quantity
    reverse = 1;  // Preserve the direction
  }
  if (speed > 400)  // Max PWM dutycycle
    speed = 400;
  /* older version 
  #ifdef DUALMC33926MOTORSHIELD_TIMER1_AVAILABLE
    if (_M1PWM == _M1PWM_TIMER1_PIN && _M2PWM == _M2PWM_TIMER1_PIN)
    {
      OCR1B = speed;
    }
    else
    {
      analogWrite(_M2PWM,speed * 51 / 80); // map 400 to 255
    }
  #else
    analogWrite(_M2PWM,speed * 51 / 80); // map 400 to 255
  #endif*/
	#if defined(__AVR_ATmega168__)|| defined(__AVR_ATmega328P__)
	  OCR1A = speed;
	#else
	  analogWrite(_M2PWM, speed * 51 / 80); // default to using analogWrite, mapping 400 to 255
	#endif
  if (reverse)
    digitalWrite(_M2DIR,HIGH);
  else
    digitalWrite(_M2DIR,LOW);
}//end for setM2Speed

// Set speed for motor 3, speed is a number betwenn -400 and 400
void DualMC33926Motor3Shield::setM3Speed(int speed)
{
	unsigned char reverse = 0;

	if (speed < 0)
	{
		speed = -speed;  // Make speed a positive quantity
		reverse = 1;  // Preserve the direction
	}
	if (speed > 400)  // Max PWM dutycycle
		speed = 400;
	/* older version
	#ifdef DUALMC33926MOTORSHIELD_TIMER1_AVAILABLE
	  if (_M1PWM == _M1PWM_TIMER1_PIN && _M2PWM == _M2PWM_TIMER1_PIN)
	  {
		OCR1B = speed;
	  }
	  else
	  {
		analogWrite(_M2PWM,speed * 51 / 80); // map 400 to 255
	  }
	#else
	  analogWrite(_M2PWM,speed * 51 / 80); // map 400 to 255
	#endif*/

	// newer version
	#if defined(__AVR_ATmega168__)|| defined(__AVR_ATmega328P__)
		OCR1A = speed;
	#else
		analogWrite(_M3PWM, speed * 51 / 80); // default to using analogWrite, mapping 400 to 255
	#endif
	if (reverse)
		digitalWrite(_M3DIR, HIGH);
	else
		digitalWrite(_M3DIR, LOW);
}//end for setM3peed

// Set speed for motor 4, speed is a number betwenn -400 and 400
void DualMC33926Motor3Shield::setM4Speed(int speed)
{
	unsigned char reverse = 0;

	if (speed < 0)
	{
		speed = -speed;  // Make speed a positive quantity
		reverse = 1;  // Preserve the direction
	}
	if (speed > 400)  // Max PWM dutycycle
		speed = 400;
	/* older version
	#ifdef DUALMC33926MOTORSHIELD_TIMER1_AVAILABLE
	  if (_M1PWM == _M1PWM_TIMER1_PIN && _M2PWM == _M2PWM_TIMER1_PIN)
	  {
		OCR1B = speed;
	  }
	  else
	  {
		analogWrite(_M2PWM,speed * 51 / 80); // map 400 to 255
	  }
	#else
	  analogWrite(_M2PWM,speed * 51 / 80); // map 400 to 255
	#endif*/

	// newer version
	#if defined(__AVR_ATmega168__)|| defined(__AVR_ATmega328P__)
		OCR1A = speed;
	#else
		analogWrite(_M4PWM, speed * 51 / 80); // default to using analogWrite, mapping 400 to 255
	#endif
	if (reverse)
		digitalWrite(_M4DIR, HIGH);
	else
		digitalWrite(_M4DIR, LOW);
}//end for setM4peed

// Set speed for motor 5, speed is a number betwenn -400 and 400
void DualMC33926Motor3Shield::setM5Speed(int speed)
{
	unsigned char reverse = 0;

	if (speed < 0)
	{
		speed = -speed;  // Make speed a positive quantity
		reverse = 1;  // Preserve the direction
	}
	if (speed > 400)  // Max PWM dutycycle
		speed = 400;
	/* older version
	#ifdef DUALMC33926MOTORSHIELD_TIMER1_AVAILABLE
	  if (_M1PWM == _M1PWM_TIMER1_PIN && _M2PWM == _M2PWM_TIMER1_PIN)
	  {
		OCR1B = speed;
	  }
	  else
	  {
		analogWrite(_M2PWM,speed * 51 / 80); // map 400 to 255
	  }
	#else
	  analogWrite(_M2PWM,speed * 51 / 80); // map 400 to 255
	#endif*/

	// newer version
	#if defined(__AVR_ATmega168__)|| defined(__AVR_ATmega328P__)
		OCR1A = speed;
	#else
		analogWrite(_M5PWM, speed * 51 / 80); // default to using analogWrite, mapping 400 to 255
	#endif
	if (reverse)
		digitalWrite(_M5DIR, HIGH);
	else
		digitalWrite(_M5DIR, LOW);
}//end for setM5speed

// Set speed for motor 6, speed is a number betwenn -400 and 400
void DualMC33926Motor3Shield::setM6Speed(int speed)
{
	unsigned char reverse = 0;

	if (speed < 0)
	{
		speed = -speed;  // Make speed a positive quantity
		reverse = 1;  // Preserve the direction
	}
	if (speed > 400)  // Max PWM dutycycle
		speed = 400;
	/* older version
	#ifdef DUALMC33926MOTORSHIELD_TIMER1_AVAILABLE
	  if (_M1PWM == _M1PWM_TIMER1_PIN && _M2PWM == _M2PWM_TIMER1_PIN)
	  {
		OCR1B = speed;
	  }
	  else
	  {
		analogWrite(_M2PWM,speed * 51 / 80); // map 400 to 255
	  }
	#else
	  analogWrite(_M2PWM,speed * 51 / 80); // map 400 to 255
	#endif*/

	// newer version
	#if defined(__AVR_ATmega168__)|| defined(__AVR_ATmega328P__)
		OCR1A = speed;
	#else
		analogWrite(_M6PWM, speed * 51 / 80); // default to using analogWrite, mapping 400 to 255
	#endif
	if (reverse)
		digitalWrite(_M6DIR, HIGH);
	else
		digitalWrite(_M6DIR, LOW);
}//end for setM6speed

/////////////
// Set speed for motor 1, 2, 3, 4, 5, and 6
void DualMC33926Motor3Shield::setSpeeds(int m1Speed, int m2Speed, int m3Speed, int m4Speed, int m5Speed, int m6Speed)
{
  setM1Speed(m1Speed);
  setM2Speed(m2Speed);
  setM3Speed(m3Speed);
  setM4Speed(m4Speed);
  setM5Speed(m5Speed);
  setM6Speed(m6Speed);
} //end of set speeds

// ******* END OF SETTING SPEEDS ******* //


// ******* READ CURRENT VALUE IN mA FOR EACH MOTORS ******* //
// Return motor 1 current value in milliamps.
unsigned int DualMC33926Motor3Shield::getM1CurrentMilliamps()
{
  // 5V / 1024 ADC counts / 525 mV per A = 9 mA per count
  return analogRead(_M1FB) * 9;
}

// Return motor 2 current value in milliamps.
unsigned int DualMC33926Motor3Shield::getM2CurrentMilliamps()
{
  // 5V / 1024 ADC counts / 525 mV per A = 9 mA per count
  return analogRead(_M2FB) * 9;
}

// Return motor 3 current value in milliamps.
unsigned int DualMC33926Motor3Shield::getM3CurrentMilliamps()
{
	// 5V / 1024 ADC counts / 525 mV per A = 9 mA per count
	return analogRead(_M3FB) * 9;
}

// Return motor 4 current value in milliamps.
unsigned int DualMC33926Motor3Shield::getM4CurrentMilliamps()
{
	// 5V / 1024 ADC counts / 525 mV per A = 9 mA per count
	return analogRead(_M4FB) * 9;
}

// Return motor 5 current value in milliamps.
unsigned int DualMC33926Motor3Shield::getM5CurrentMilliamps()
{
	// 5V / 1024 ADC counts / 525 mV per A = 9 mA per count
	return analogRead(_M5FB) * 9;
}

// Return motor 6 current value in milliamps.
unsigned int DualMC33926Motor3Shield::getM6CurrentMilliamps()
{
	// 5V / 1024 ADC counts / 525 mV per A = 9 mA per count
	return analogRead(_M6FB) * 9;
}
// ******* END OF READING CURRENT VALUES ******* //

// ******* RETURN ERROR STATUS ******* //
unsigned char DualMC33926Motor3Shield::getFault()
{
  return !digitalRead(_nSF);
  return !digitalRead(_nSF2);
  return !digitalRead(_nSF3);
}
