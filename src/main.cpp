#include <Arduino.h>

#define PinA 12
#define PinZ 27

volatile int counter=0;
unsigned long previousMillis = 0;
long interval = 1000;
volatile int rotator=0;
volatile int Encoderrotator =0;
int old_Encoderrotator;
int old_rotator = rotator;

void interruptor(); 
void updateEncoder();

void setup()
{
  pinMode(PinA, INPUT);
  pinMode(PinZ, INPUT);
	Serial.begin(115200);
  attachInterrupt(PinA,interruptor,RISING);
  attachInterrupt(PinZ,updateEncoder,RISING);
  old_Encoderrotator = Encoderrotator;
}

void loop(){

  if (old_Encoderrotator != Encoderrotator)
    {
      Serial.print("NB ROTATION : ");
      Serial.println(Encoderrotator);
      old_Encoderrotator = Encoderrotator;

      Serial.print("A value : ");
      Serial.println(counter);
    }

}

void interruptor() 
{
  counter++;
}

void updateEncoder()
{
  Encoderrotator++;
}
