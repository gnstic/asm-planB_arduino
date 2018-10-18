#include <Arduino.h>
/****************************************************************
 *    Author Name: Far Zainal
 *    Date:   10/7/2018 
 *    Sketch Name: RASM_arduino wrist
 *    Sketch Description:  
 *    
 *
 *    Pin Usage:      Pin type/number    Hardware 
 *                    ----------------   ----------------
 *                    
 *****************************************************************/
 
/****************************
 ** #defines and #includes **
 ****************************/ 
    //void init(); // Initialize TIMER 1, set the PWM to 20kHZ.
    void setM1Speed(int speed); // Set speed for M1.
    unsigned char getM1Fault(); // Get fault reading.
    
    unsigned char _M1IN1;
    unsigned char _M1IN2;
    unsigned char _M1PWM_D1;
    static const unsigned char _PWM1_TIMER1_PIN = 9;
    unsigned char _M1SF;
    unsigned char _M1FB;
    unsigned char _EN1;
    unsigned char _M2IN1;
    unsigned char _M2IN2;
    unsigned char _M2PWM_D1;
    unsigned char _M2SF;
    unsigned char _M2FB;
    unsigned char _D2;

 
/***********************
 ** Global Variables ***
 ***********************/
// *** Declare & Initialize ANALOG Pins ***

// *** Declare & Initialize DIGITAL Pins ***
  
// *** Declare & Initialize Program Variables ***

  
/********************
 ** Setup Function **
 ********************/  
void setup(void){
  // PUT YOUR SETUP CODE HERE, TO RUN ONCE:
  
    _M1IN1 = 2;
    _M1IN2 = 4;
    _M1PWM_D1 = 9;
    _M1SF = 12;
    _M1FB = A0;
   // _EN1 = 6;
    _D2 = 7;

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
  //pinMode(_EN1, OUTPUT); digitalWrite(_EN1, HIGH);
  Serial.println("Enable is ON");
  pinMode(_D2, OUTPUT); digitalWrite(_D2, LOW);

    //#ifdef DUALMC33926MOTORSHIELD_TIMER1_AVAILABLE
    //if (_M1PWM_D1 == _M1PWM_TIMER1_PIN)
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
    Serial.println("timer is availble");
    }
    #endif
  // *** Configure Digital Pins & Attach Servos ***
  
      //md.init(); // intialize the motors pin;

  // *** Initialize Serial Communication ***
     Serial.begin(9600);     
     Serial.println("Dual MC 339256 shields program is starting;");
     
  // *** Take Initial Readings ***  
}// end setup() function

/*******************
 ** Loop Function **
 *******************/
void loop(void){
  //PUT YOUR MAIN CODE HERE, TO RUN REPEATEDLY
  //testMotor1();
  Serial.println("motor 1 is driving");
  setM1aSpeed(400);
  delay(2000);  //delay 2 seconds
  setM1aSpeed(0);
  Serial.println("stop");
  delay(2000);
  setM1aSpeed(-400);
  delay(5000);
  setM1aSpeed(0);
  delay(5000);
  Serial.println("stop");
} // end loop() function

/****************************
 ** User-Defined Functions **
 ****************************/
// create custom headings as necessary to clearly organize your sketch
// e.g., Button functions, DC Motor functions, Servo functions, etc.
 /*void testMotor1(){ // for testing motor 1
  md.setM1Speed(400); // max value 400;
  delay(1000);
  md.setM1Speed(0);
  delay(100);
  md.setM1Speed(-400); // max value 400;
  delay(1000);
  md.setM1Speed(0); // stop the motor
  delay(100);
 } // end of testing motor 1*/

void setM1aSpeed(int speed)
{
  unsigned char reverse = 0;

  if (speed < 0)
  {
    speed = -speed;  // Make speed a positive quantity
    reverse = 1;  // Preserve the direction
    Serial.println ("reverse speed is set");
  }
  if (speed > 400)  // Max PWM dutycycle
    speed = 400;

  //newer version
  /*#if defined(__AVR_ATmega168__)|| defined(__AVR_ATmega328P__)
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
      digitalWrite(_M1PWM_D1,speed); // map 400 to 255
      digitalWrite(D2,LOW);
    }
  #else
    digitalWrite(_M1PWM_D1,speed); // map 400 to 255
  #endif
  
  if (reverse){
  digitalWrite(_M1IN1, LOW);
  digitalWrite(_M1IN2, HIGH);
  Serial.println("reverse direction is set");
  }
    
  else if(speed == 0){
    digitalWrite(_M1IN1, LOW);
    digitalWrite(_M1IN2, LOW);
  }
  else{
  digitalWrite(_M1IN1, HIGH);
  digitalWrite(_M1IN2, LOW);
  }
} // end of setM1Speed
