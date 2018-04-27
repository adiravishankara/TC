include <Servo.h>
Servo myESC;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  myESC.attach(12);
  myESC.write(30);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
