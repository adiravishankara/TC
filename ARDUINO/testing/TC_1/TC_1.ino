#include <Servo.h>
// objects to read/write PWM
Servo myESC;

//pin values
const int wind_Input = A2;
const int motor_Output = 12; //This controls the motor, sends out a PWM
const int TC_ESC = A4; //The Analog Signal of 
const int OPRPM = A6; //optical RPM
float windSpeed,wSD, P = 0.09,pwmD = 40;
float start_Time,pwm;
float RPM;
boolean sys_Start = false;

int esc_Speed = 30;

void setup() {
  // put your setup code here, to run once:
  pinMode(wind_Input, INPUT);
  pinMode(TC_ESC, INPUT);

  Serial.begin(115200);
  
  myESC.attach(motor_Output);
  //while(!myESC.attached()){ myESC.attach(motor_Output);}
  myESC.write(30);



  
}

void loop() {
  // put your main code here, to run repeatedly:
  TC_Sync();
  if(sys_Start == true){
    windSpeed = readWind();    
    RPM = analogRead(OPRPM);
    pwm = motor_Control(windSpeed);
    analogWrite(motor_Output, pwm);
  	Serial.print(millis() - start_Time);
  	Serial.print(",");
  	Serial.print(windSpeed);
  	Serial.print(",");
  	Serial.print(RPM);
  	Serial.print(",");
  	Serial.println(pwm);
  }
}


float readWind(){
	return analogRead(wind_Input);
}


void TC_Sync(){
  int TC_signal = pulseIn(TC_ESC,HIGH);
  if(TC_signal > 1500){
    timer_start();
    sys_Start = true;} 
}
float motor_Control(float windSpeed){
  float err = wSD - windSpeed;
  float uC = P*err;
  pwm = pwmD + pwmD*uC;
  return pwm;
}
void timer_start(){

	start_Time = millis();
} 
