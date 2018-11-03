/****************************************************************
 *    Author Name: Far Zainal
 *    Date:   10/7/2018 
 *    Sketch Name: RASM_arduino wrist
 *    Sketch Description:  
 *                    
 *****************************************************************/
 
/****************************
 ** #defines and #includes **
 ****************************/ 
 #include "dualMC33926_motorDriver1.h"; 
 dualMC33926_motorDriver1 md;
 
/***********************
 ** Global Variables ***
 ***********************/
 char comm ='a'; //command to run == "o" 
 char c;
 int myEnc1; // the reading value of shoulder encoder
 int oldEnc1 = 0;
 int myEnc2; // the reading value of the elbow encoder
 int oldEnc2 = 0;
 
 
 int enc1 = A0; 
 int enc2 = A1;

  unsigned long t = micros();

  // PID control variable;
  double Kp = 0.32;
  double Kd = 0.3/8;
  double Ki = 0.1;
  float error = 0;
  float errorOld = 0;
  float dError = 0;
  float totalError = 0;
  double V = 0;

  int posOld = 0; 
  
/********************
 ** Setup Function **
 ********************/  
void setup(void){  
  // *** Configure Digital Pins & Attach Servos ***
      md.init(); // intialize the motors pin;
      pinMode(enc1, INPUT);
      pinMode(enc2, INPUT);
      
  // *** Initialize Serial Communication ***
     Serial.begin(9600);          
     
  // *** Take Initial Readings ***  
      Serial.println("Program is running");
      Serial.print("Command; \ns to run test motor 1\nw to run test motor 2\n");
      encoderRead(); // read the encoders initial value
      Serial.println("please enter r");
      while(comm!='r'){        
        comm = Serial.read();
        if(comm == 'r'){
          break;
        }
      }
}// end setup() function

/*******************
 ** Loop Function **
 *******************/
void loop(void){
  //PUT YOUR MAIN CODE HERE, TO RUN REPEATEDLY

  readCommand();

  if(c == '2'){
    double tOld = 0;
    encoderRead();
    int intDesPos = myEnc2 + 40;
    int desPos = myEnc2;
    int posOld = myEnc2;
    Serial.print("The desired Position: \t");Serial.print(intDesPos); Serial.print("\tStarting Position: "); Serial.println(myEnc2); 
    while(myEnc2 < intDesPos -2){
      encoderRead();
      if(myEnc2 <100 || myEnc2 > 900){
        Serial.println("Break break break");        
        break;
      }
      double t = micros()/1000000.0;   

      double vel = (myEnc2 - posOld)/(t - tOld);
      
      error = intDesPos - myEnc2;
      dError = (error - errorOld)/(t - tOld);
      totalError += error;
      V = Kp*error + Kd*dError + Ki*totalError;
      double M = V*155/5.0;
      M = constrain(M, -155, 155);
      //md.setM1Speed(M);
      md.setM2Speed(M);
      md.setM1Brake(400);

      // print values
      //Serial.print("The M is\t"); Serial.println(M);
      //Serial.print("The error: "); Serial.println(error);
      //Serial.print("\tThe d_error: "); Serial.println(dError);
      //Serial.print("time : ");Serial.print(t); Serial.print("\t time old: "); Serial.println(tOld);      
      //Serial.print("The current Position: ");Serial.println(myEnc2);
      //Serial.print("The velocity: "); 
      Serial.println(vel);
      
      // save current time and position to old time and old position
      tOld = t;
      posOld = myEnc2;
      errorOld = error;
      
    } // end of while loop;
    
    Serial.println("Done");
    Serial.print("Final Position: "); Serial.println(myEnc2); 
    md.setM2Brake(400);
    md.setM2Speed(0);
    c == '9';   
  } // end for c = 2

    // c = 3
    if(c == '3'){
    double tOld = 0;
    encoderRead();
    int intDesPos = myEnc2 - 40;
    int desPos = myEnc2;
    Serial.print("The desired Position: \t");Serial.print(intDesPos); Serial.print("\tStarting Position: "); Serial.println(myEnc2); 
    while(myEnc2 > intDesPos -2){
      encoderRead();
      if(myEnc2 <100 || myEnc2 > 900){
        Serial.println("Break break break");        
        break;
      }
      double t = micros()/1000000.0;
      //desPos = myEnc2 + 2;     
      
      error = intDesPos - myEnc2;
      dError = (error - errorOld)/(t - tOld);
      totalError += error;
      V = Kp*error + Kd*dError + Ki*totalError;
      double M = V*155/5.0;
      M = constrain(M, -155, 155);
      //md.setM1Speed(M);
      md.setM2Speed(M);
      md.setM1Brake(400);

      //Serial.print("The M is\t");      Serial.println(M);
      //Serial.print("The error: ");      Serial.println(error);
      //Serial.print("\tThe d_error: ");
      //Serial.println(dError);
      //Serial.print("time : ");Serial.print(t); Serial.print("\t time old: "); Serial.println(tOld);      
      Serial.print("The current Position: ");Serial.println(myEnc2);
      
      // save current time and position to old time and old position
      tOld = t;
      errorOld = error;
      
    } // end of while loop;
    
    Serial.println("Done");
    Serial.print("Final Position: "); Serial.println(myEnc2); 
    md.setM2Brake(400);
    md.setM2Speed(0);
    c == '9';   
  } // end for c = 3

  if(c == '3'){
    encoderRead();
    Serial.print("The current Position: ");Serial.println(myEnc2);
    delay(500);
  }
  
   delay(10);

} // end loop() function

/****************************
 ** User-Defined Functions **
 ****************************/

 void testMotor1(){ // for testing motor 1
  md.setM1Speed(255); // max value 400;
  md.setM2Brake(400);
  delay(500);
  md.setM1Brake(400);
  delay(1000);
  md.setM1Speed(-255); // max value 400;
  md.setM2Brake(400);
  delay(500);
  md.setM1Brake(400);
  md.setM1Speed(0);
  delay(500);
 } // end of testing motor 1

  void testMotor2(){ //for testing motor 2
  md.setM2Speed(255); // max value 400;
  md.setM1Brake(400);
  delay(500);
  md.setM2Brake(400); // stop the motor
  delay(1000);
  md.setM2Speed(-255); // max value 400;
  md.setM1Brake(400);
  delay(500);
  md.setM2Speed(0); // stop the motor
  delay(500);
 } // end of testing motor 2

  void readCommand(){
    if(Serial.available() >0){
      c = Serial.read();
      Serial.flush();
    }
  } // end of read command

  void encoderRead(){
    myEnc1 = analogRead(enc1);
    myEnc2 = analogRead(enc2);
    /*Serial.print("Encoder 1: ");
    Serial.print(myEnc1);
    Serial.print("\tEncoder 2: ");
    Serial.println(myEnc2);*/
  } // end of encoder read

