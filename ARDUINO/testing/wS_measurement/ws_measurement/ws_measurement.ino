#include <Servo.h>

Servo myESC;

//PINS
const int wind_Input = A2;
const int motor_Output = 12;
const int OptRPM = A6;
int stopper = 0;

//Variables
int pwm, pwmD = 55;
float wSD = 500, P = 0.09, wS, rpm;
float runTime;

void setup()
{
	pinMode(wind_Input,INPUT);
	pinMode(OptRPM,INPUT);
	runTime = millis();
	Serial.begin(115200);

	//Starting the Servo
	myESC.attach(motor_Output);
	myESC.write(30);
  delay(3000);

	//Printing the Headers and initial values.
    
    Serial.println("Time   WindV   RPM   PWM");
    Serial.print(millis()-runTime);
    Serial.print(",");
    Serial.print(wS);
    Serial.print(",");
    Serial.print(rpm);
    Serial.print(",");
    Serial.println(pwm);

}	
void loop()

{
    stopper1();
	  if(stopper != 0){
    pwm = 30;
    Serial.println("STOPPED");
    break;
  }
    else{
      pwm = pwmD;}
      
	wS = readWind();
	//rpm = readRPM();

	myESC.write(pwm);
	Serial.print(millis()-runTime);
  Serial.print(",");
  Serial.print(wS);
  Serial.print(",");
  //Serial.print(rpm);
  //Serial.print(",");
  Serial.println(pwm);

  delay(10);

}
float readWind(){
	return analogRead(wind_Input);
}
float readRPM(){
	return analogRead(OptRPM);
}
int setPWM(float wS){
	float err = wSD - wS;
	float uC = P*err;
	int P = int(pwmD + pwmD*uC);
	return P;
}
void stopper1(){
  if(Serial.available()){
    stopper = Serial.read();
  }
}

