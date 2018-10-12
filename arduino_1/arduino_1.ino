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
 #include "DualVNH5019MotorShield.h"
 #include "Encoder.h"
 DualVNH5019MotorShield md;

 // *** define the motor pins ***
 // control pins

 // enable pins

 
/***********************
 ** Global Variables ***
 ***********************/
// *** Declare & Initialize ANALOG Pins ***

// *** Declare & Initialize DIGITAL Pins ***

// *** Create Servo Objects ***
  
// *** Declare & Initialize Program Variables ***
  // time variables
  unsigned long t_ms;   // t_ms = micros(); time in microseconds using the arduino plugin
  double t = 0;         // current time in seconds
  double timeOld = 0;   // the previous time or timestep
  double desAngVel = 0; // the desired angular velocity
  
/********************
 ** Setup Function **
 ********************/  
void setup(void){
  // PUT YOUR SETUP CODE HERE, TO RUN ONCE:

  // *** Configure Digital Pins & Attach Servos ***
  
  // *** Initialize Serial Communication ***
     
  // *** Take Initial Readings ***
  
  // *** Move Hardware to Desired Initial Positions ***
  
}// end setup() function

/*******************
 ** Loop Function **
 *******************/
void loop(void){
  //PUT YOUR MAIN CODE HERE, TO RUN REPEATEDLY
  
} // end loop() function

/****************************
 ** User-Defined Functions **
 ****************************/
// create custom headings as necessary to clearly organize your sketch
// e.g., Button functions, DC Motor functions, Servo functions, etc.
