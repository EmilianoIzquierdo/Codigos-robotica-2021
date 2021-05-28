int LEDV = 13;
int pin = 3; 
long tiempo1=0;
long tiempo2=0; 
int LEDR = 8;

void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
attachInterrupt(digitalPinToInterrupt(pin), can, RISING);
}
void loop()
{  
 
}
  

           
        
           
  void can(){
    
   tiempo1 = millis();
  if((tiempo1-tiempo2)>2000){
    tiempo2=tiempo1;
 Serial.println("Interrupción activada");



      
  }
}

