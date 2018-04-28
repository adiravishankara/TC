include <Servo.h>
// objects to read/write PWM
Servo myESC;

//pin values
const int wind_Input = A2;
const int motor_Output = 12;
const int TC_ESC = A4;
const int OPRPM = A6;
float windSpeed;
float start_Time;

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








	Serial.print(millis() - start_time);
	Serial.print(",");
	Serial.print(windSpeed);
	Serial.print(",");
	Serial.print(OPRPM);
	Serial.print(",");
	Serial.println(PWM);
}


float readWind(){
	return analogRead(wind_Input);
}


boolean TC_Sync(){
  int TC_signal = pulseIn(TC_ESC,HIGH);
  if(TC_signal > 1500) return true;
  else return false; 
}
int motor_Control(float windSpeed){

}
void timer_start(){
	start_time = millis();
}