const int sensor = 10;
int sens_val;
void setup()
{
	pinMode(sensor, INPUT);
	Serial.begin(9600);
	Serial.println("Board Input");
}
void loop()
{
	sens_val = analogRead(sensor);
	Serial.println(sens_val);
}