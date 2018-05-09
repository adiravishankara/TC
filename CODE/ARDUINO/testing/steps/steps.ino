#include <Servo.h>

Servo myESC;

const int wind_Input = A2;
const int motor_Output = 12; //This controls the motor, sends out a PWM
const int activation = A3; //This controls the activation signal from the RC board


float runTime;

int wS, wsD = 680; //these values are the wind speed, and desired wind speed
float P = 0.0040, pwmD = 40; //these values are for the control system.

int active = 0; //This will read the esc output of the RCboard
int pwm = 30;
int startTime, sysStatus = 0;

void setup(){
  pinMode(wind_Input,INPUT);
  pinMode(activation,INPUT);

  Serial.begin(115200);
  
  myESC.attach(motor_Output);
  myESC.write(pwm);
  delay(3000);
  startTime = millis();
  wS = analogRead(wind_Input);
  Serial.print("TIME(ms), WINDSPEED(V), PWM(deg), STATUS");
  Serial.print(millis() - startTime);
  Serial.print(",");
  Serial.print(wS);
  Serial.print(",");
  Serial.print(pwm);
  Serial.print(",");
  Serial.println(sysStatus);
}

void loop()
{
  
  active = pulseIn(activation,HIGH);
  if(active > 1500){
    sysStatus = 1;
    steps(30,30);
    steps(30,38);
    steps(30,39);
    steps(30,40);
    steps(30,41);
    steps(30,42);
    steps(30,43);
    steps(30,44);
    steps(30,45);
    steps(30,46);
    steps(30,47);
    steps(30,48);
    steps(30,49);
    steps(30,50);
    //steps(5,40);
    //steps(5,45);
    //steps(5,50);
  }
  else if (active < 1000){
    pwm = 30;
    myESC.write(pwm);
    sysStatus = 0;
  }
  wS = analogRead(wind_Input);
  Serial.print(millis() - startTime);
  Serial.print(",");
  Serial.print(wS);
  Serial.print(",");
  Serial.print(pwm);
  Serial.print(",");
  Serial.println(sysStatus);

}
void steps(int time, int pwm1){
  int currTime = millis();
  while(millis() - currTime < time*1000){
    myESC.write(pwm1);
    wS = analogRead(wind_Input);
    Serial.print(millis() - startTime);
    Serial.print(",");
    Serial.print(wS);
    Serial.print(",");
    Serial.print(pwm1);
    Serial.print(",");
    Serial.println(sysStatus);
  }
}
