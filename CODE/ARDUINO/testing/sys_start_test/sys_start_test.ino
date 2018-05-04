#include <Servo.h>

Servo signal1;
const int start_Pin = A10;
int F;
void setup() {
  // put your setup code here, to run once:
  //signal1.attach(2);
  
  pinMode(start_Pin,INPUT);
  Serial.begin(115200);
  Serial.println("Input Voltage");
}

void loop() {
  // put your main code here, to run repeatedly:
  F = pulseIn(start_Pin,HIGH);
  Serial.println(F);
  if(F > 0){
    Serial.println("WE GOT THIS");
    
  }
  //Serial.println(signal1.read());
}
