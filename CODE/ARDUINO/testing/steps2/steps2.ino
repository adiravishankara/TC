#include <Servo.h>
// objects to read/write PWM
Servo myESC;

//pin values
const int wind_Input = A2;
const int motor_Output = 12; //This controls the motor, sends out a PWM
const int activation = A3; //This controls the activation signal from the RC board

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
  wS = analogRead(wind_Input);
  active = pulseIn(activation,HIGH);
  if(active > 1500){
    sysStatus = 1;
    //pwm = pwmD;
    pwm = motor_Control(wS,pwm);
  }
  pwm = constrain(pwm,0,80);
  myESC.write(pwm);
  Serial.print(millis() - startTime);
  Serial.print(",");
  Serial.print(wS);
  Serial.print(",");
  Serial.print(pwm);
  Serial.print(",");
  Serial.println(sysStatus);
}
float motor_Control(float windSpeed,float ppwm){
  int err = wsD - windSpeed;
  float uC = P*err;
  pwm = pwmD + pwmD*uC;

  


  return pwm;
}
void step(int seconds, int pwm){
  
}

