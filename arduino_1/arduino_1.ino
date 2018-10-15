#include "DualMC33926Motor3Shield.h";

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
DualMC33926Motor3Shield md;

 // *** define the motor pins ***
 // control pins

 // enable pins

 
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

  // *** Configure Digital Pins & Attach Servos ***
      md.init();
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
  int i = 0;
  while(i<4){
    if (i == 0){
      Serial.println("Testing shield 1, motor 1;");
    }
    if (i == 1){
      Serial.println("Testing shield 1, motor 2;");
    }
    if (i == 2){
      Serial.println("Testing shield 2, motor 1;");
    }
    if (i == 3){
      Serial.println("Testing shield 2, motor 2;");
    }    
    if (i == 4){
      Serial.println("Testing shield 3, motor 1;");
    }
    delay(500);   
    i = i+1; // increment i step
  }
  Serial.println("program has ended");
} // end loop() function

/****************************
 ** User-Defined Functions **
 ****************************/
// create custom headings as necessary to clearly organize your sketch
// e.g., Button functions, DC Motor functions, Servo functions, etc.
 void testMotor1(){
  md.setM1Speed(255);
  delay(500);
  md.setM1Speed(0);
  delay(100);
  md.setM1Speed(-255);
  delay(500);
  md.setM1Speed(0);
  delay(100);
 } // end of testing motor 1

  void testMotor2(){
  md.setM2Speed(255);
  delay(500);
  md.setM2Speed(0);
  delay(100);
  md.setM2Speed(-255);
  delay(500);
  md.setM2Speed(0);
  delay(100);
 } // end of testing motor 2

  void testMotor3(){
  md.setM3Speed(255);
  delay(500);
  md.setM3Speed(0);
  delay(100);
  md.setM3Speed(-255);
  delay(500);
  md.setM3Speed(0);
  delay(100);
 } // end of testing motor 3

   void testMotor4(){
  md.setM4Speed(255);
  delay(500);
  md.setM4Speed(0);
  delay(100);
  md.setM4Speed(-255);
  delay(500);
  md.setM4Speed(0);
  delay(100);
 } // end of testing motor 2

  void testMotor5(){
  md.setM5Speed(255);
  delay(500);
  md.setM5Speed(0);
  delay(100);
  md.setM5Speed(-255);
  delay(500);
  md.setM5Speed(0);
  delay(100);
 } // end of testing motor 3

