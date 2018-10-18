<<<<<<< HEAD
/* This is the motor shield library that will be used on RASM. The library is for Pololu Dual MC 33926 motor shield. The RASM will use 3 motor shields, that will connect to 5 DC motors*/

// include DualMC33926 header file
//#include "Arduino.h"
#include "dualMC33926_motorDriver1.h"


// Constructors ////////////////////////////////////////////////////////////////

// default pins for the library, and for the time being this library only supports default pins connections
dualMC33926_motorDriver1::dualMC33926_motorDriver1()
{
  //Default Pin Map for motor shield 1
  /*_nD2 = 4;		// tri-state disable both outputs of both motor channels when LOW, toggling resets latched driver fault condition
  _M1DIR = 7;	// motor 1 direction
  _M1PWM = 9;	// motor 1 speed (digital PWM)
  _M2DIR = 8;	// motor 2 direction
  _M2PWM = 10;	// motor 2 speed (digital PWM)
  _nSF = 12;	// status flag indicator (LOW indicates fault)
  _M1FB =A0;	//analog 0; motor 1 current sense output (525mV/A)
  _M2FB =A1;	// analog 1; motor 2 current sense output (525mV/A)
  */

  // dEFAULT PIN MAP FOR MOTOR SHIELD 1
  _M1IN1 = 2;
  _M1IN2 = 4;
  _M1PWM_D1 = 9;
  _M1SF = 12;
  _M1FB = A0;
  _EN1 = 6;
  
  _M2IN1 = 7;
  _M2IN2 = 8;
  _M2PWM_D1 = 10;
  _M2SF = 11;
  _M2FB = A1;
}

// Public Methods //////////////////////////////////////////////////////////////
void dualMC33926_motorDriver1::init()
{
// Define pinMode for the pins and set the frequency for timer1.
	// intialization for motor shield 1
  pinMode(_M1IN1, OUTPUT);
  pinMode(_M1IN2, OUTPUT);
  pinMode(_M1PWM_D1, OUTPUT);
  pinMode(_M1SF, INPUT);
  pinMode(_M1FB, INPUT);
  pinMode(_M2IN1, OUTPUT);
  pinMode(_M2IN2, OUTPUT);
  pinMode(_M2PWM_D1, OUTPUT);
  pinMode(_M2SF, INPUT);
  pinMode(_M2FB, INPUT);
  pinMode(_EN1, OUTPUT); digitalWrite(_EN1, HIGH);


  #ifdef DUALMC33926MOTORSHIELD_TIMER1_AVAILABLE
    if (_M1PWM_D1 == _M1PWM_TIMER1_PIN)
//#if defined(__AVR_ATmega168__)|| defined(__AVR_ATmega328P__)
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
void dualMC33926_motorDriver1::setM1Speed(int speed)
{
  unsigned char reverse = 0;

  if (speed < 0)
  {
    speed = -speed;  // Make speed a positive quantity
    reverse = 1;  // Preserve the direction
  }
  if (speed > 400)  // Max PWM dutycycle
    speed = 400;

	/* newer version
	#if defined(__AVR_ATmega168__)|| defined(__AVR_ATmega328P__)
	  OCR1A = speed;
	#else
	  analogWrite(_M1PWM_D1, speed * 51 / 80); // default to using analogWrite, mapping 400 to 255
	#endif*/
	
  #ifdef DUALMC33926MOTORSHIELD_TIMER1_AVAILABLE
    if (_M1PWM_D1 == _M1PWM_TIMER1_PIN)
    {
      OCR1A = speed;
    }
    else
    {
      analogWrite(_M1PWM_D1,speed * 51 / 80); // map 400 to 255
    }
  #else
    analogWrite(_M1PWM_D1,speed * 51 / 80); // map 400 to 255
  #endif
  
  if (reverse){
	digitalWrite(_M1IN1, LOW);
	digitalWrite(_M1IN1, HIGH);
  }
    
  else if(speed == 0){
	  digitalWrite(_M1IN1, LOW);
	  digitalWrite(_M1IN2, LOW);
  }
  else{
    digitalWrite(_M1IN1, HIGH);
	digitalWrite(_M1IN1, LOW);
  }
} // end of setM1Speed

// ******* END OF SETTING SPEEDS ******* //


// ******* READ CURRENT VALUE IN mA FOR EACH MOTORS ******* //


// ******* END OF READING CURRENT VALUES ******* //

// ******* RETURN ERROR STATUS ******* //
unsigned char dualMC33926_motorDriver1::getM1Fault()
{
  return !digitalRead(_M1SF);
}
=======
/* This is the motor shield library that will be used on RASM. The library is for Pololu Dual MC 33926 motor shield. The RASM will use 3 motor shields, that will connect to 5 DC motors*/

// include DualMC33926 header file
//#include "Arduino.h"
#include "dualMC33926_motorDriver1.h"


// Constructors ////////////////////////////////////////////////////////////////

// default pins for the library, and for the time being this library only supports default pins connections
dualMC33926_motorDriver1::dualMC33926_motorDriver1()
{
  //Default Pin Map for motor shield 1
  /*_nD2 = 4;		// tri-state disable both outputs of both motor channels when LOW, toggling resets latched driver fault condition
  _M1DIR = 7;	// motor 1 direction
  _M1PWM = 9;	// motor 1 speed (digital PWM)
  _M2DIR = 8;	// motor 2 direction
  _M2PWM = 10;	// motor 2 speed (digital PWM)
  _nSF = 12;	// status flag indicator (LOW indicates fault)
  _M1FB =A0;	//analog 0; motor 1 current sense output (525mV/A)
  _M2FB =A1;	// analog 1; motor 2 current sense output (525mV/A)
  */

  // dEFAULT PIN MAP FOR MOTOR SHIELD 1
  _M1IN1 = 2;
  _M1IN2 = 4;
  _M1PWM_D1 = 9;
  _M1SF = 12;
  _M1FB = A0;
  _EN1 = 6;
  _M2IN1 = 7;
  _M2IN2 = 8;
  _M2PWM_D1 = 10;
  _M2SF = 11;
  _M2FB = A1;
}

// Public Methods //////////////////////////////////////////////////////////////
void dualMC33926_motorDriver1::init()
{
// Define pinMode for the pins and set the frequency for timer1.
	// intialization for motor shield 1
  pinMode(_M1IN1, OUTPUT);
  pinMode(_M1IN2, OUTPUT);
  pinMode(_M1PWM_D1, OUTPUT);
  pinMode(_M1SF, INPUT);
  pinMode(_M1FB, INPUT);
  pinMode(_M2IN1, OUTPUT);
  pinMode(_M2IN2, OUTPUT);
  pinMode(_M2PWM_D1, OUTPUT);
  pinMode(_M2SF, INPUT);
  pinMode(_M2FB, INPUT);
  pinMode(_EN1, OUTPUT); digitalWrite(_EN1, HIGH);


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
void dualMC33926_motorDriver1::setM1Speed(int speed)
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
void dualMC33926_motorDriver1::setM2Speed(int speed)
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

/////////////
// Set speed for motor 1, 2, 3, 4, 5, and 6
void DualMC33926Motor3Shield::setSpeeds(int m1Speed, int m2Speed)
{
  setM1Speed(m1Speed);
  setM2Speed(m2Speed);
} //end of set speeds

// ******* END OF SETTING SPEEDS ******* //


// ******* READ CURRENT VALUE IN mA FOR EACH MOTORS ******* //
// Return motor 1 current value in milliamps.
unsigned int dualMC33926_motorDriver1::getM1CurrentMilliamps()
{
  // 5V / 1024 ADC counts / 525 mV per A = 9 mA per count
  return analogRead(_M1FB) * 9;
}

// Return motor 2 current value in milliamps.
unsigned int dualMC33926_motorDriver1::getM2CurrentMilliamps()
{
  // 5V / 1024 ADC counts / 525 mV per A = 9 mA per count
  return analogRead(_M2FB) * 9;
}

// ******* END OF READING CURRENT VALUES ******* //

// ******* RETURN ERROR STATUS ******* //
unsigned char dualMC33926_motorDriver1::getFault()
{
  return !digitalRead(_nSF);
}
>>>>>>> 0b788b28815d0795fe68a4306f71f5ddb90cd0b0
