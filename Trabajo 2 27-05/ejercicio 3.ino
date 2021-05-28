#include <Servo.h>
int pin = 3; 
long tiempo1=0;
long tiempo2=0; 
int posicion_1 = 0;
int posicion_2 = 180;
Servo mi_servo;
 int grados = 0;
bool estado = false; 

void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
attachInterrupt(digitalPinToInterrupt(pin), can, RISING);
    mi_servo.attach(7);
}
void loop()
{  
  if(estado==false){
grados= grados + 1; 
   mi_servo.write(grados);
  delay(20);
  }else if(grados==180){
    estado=true; 
  }

  
  if(estado==true){
     grados= grados - 1; 
   mi_servo.write(grados);
    delay(20);}
  
   if(grados==0){
    estado=false;}
}
  
