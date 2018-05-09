const int activation_pin = A3;
int active = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(activation_pin, INPUT);
  Serial.begin(115200);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  active = analogRead(activation_pin);
  Serial.println(active);
  delay(100);

}
