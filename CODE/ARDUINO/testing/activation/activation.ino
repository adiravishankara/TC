const int activation_pin = A3;
int active = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(activation_pin, INPUT);
  Serial.begin(115200);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  active = pulseIn(activation_pin,HIGH);
  Serial.print(active);
  Serial.print(",");
  if (active > 1000){
    Serial.println("SYSTEM ACTIVE");
  }else if(active < 1000){
    Serial.println("SYSTEM INACTIVE");
  }
}
