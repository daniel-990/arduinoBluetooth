// Bluetooth modulo Daniel y arduino placa

#include <SoftwareSerial.h>
SoftwareSerial BlueTooth(5, 6); // (TXD, RXD) del HC-06

char BT_input;
const int rele = 2;

void setup()  
{
  pinMode(13, OUTPUT);     // Arduino LED Pin
  BlueTooth.begin(9600);  
  pinMode(rele,OUTPUT);
}

void loop() 
{
  if (BlueTooth.available())
 
  {
    BT_input=(BlueTooth.read());
    if (BT_input=='1')
    {
      digitalWrite(13, HIGH);
      BlueTooth.println("ventilador enciende");
      digitalWrite(rele, HIGH);
      
    }
    else if (BT_input=='0')
    {
      digitalWrite(13, LOW);
      BlueTooth.println("ventilador apaga");
      digitalWrite(rele, LOW);
    }
   else if (BT_input=='?')
    {
      BlueTooth.println("el dato no se reconoce");
      BlueTooth.println("indique el valor 1 o 0");
    }    
  }
}