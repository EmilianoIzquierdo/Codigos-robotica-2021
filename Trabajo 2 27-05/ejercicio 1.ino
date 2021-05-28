        int distancia = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}
void setup()
{
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(7, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(3), alarma, RISING);
}
void loop()
{
  distancia = 0.01723 * readUltrasonicDistance(5, 6);
  Serial.println(distancia);
  delay(1000);
}

void alarma(){

  Serial.println("Alarma activada");
  tone(2, 300, 5000);    //suena la alarma
  digitalWrite(7, HIGH); //parpadea el led
  delay(3000);
  digitalWrite(7, LOW);
  delay(3000);

}
