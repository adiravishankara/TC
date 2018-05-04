const int sensor = A2;
int sens_val;
void setup()
{
	pinMode(sensor, INPUT);
	Serial.begin(9600);
	Serial.println("Board Input");
}
void loop()
{
readSensor();
}
void readSensor(){
  sens_val = pulseIn(sensor,HIGH);
  if(sens_val > 1000) do_this();
}void do_this(){
  Serial.println("Signal Recieved");
}

