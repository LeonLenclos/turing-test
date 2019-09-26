#include "DualVNH5019MotorShield.h"

DualVNH5019MotorShield md;

const int POTENTIOMETRE = A0;
const int vmax = 300;
long potar = 0;
long vitesse = 0;

void stopIfFault()
{
  if (md.getM1Fault())
  {
    Serial.println("M1 fault");
    while(1);
  }
  
}

void arreter()
{
      for (int i = vitesse; i >= 0; i++)
  {
    md.setM1Speed(i);
    stopIfFault();
    delay(2);
  }
}
/*
void faire_une_pause_pour_reflechir()
{
    arreter();
    attendre(duree_pause_pour_reflechir)
    demarer();
}*/

void demarer()
  {
for (int i = 0; i <= vitesse; i++)
  {
    md.setM1Speed(i);
    stopIfFault();
    delay(2);
  }
}



void setup()
{Serial.begin(9600);
  Serial.println("Dual VNH5019 Motor Shield");
  md.init();
  Serial.println("init ok");
}


void loop()
{
  potar = analogRead(POTENTIOMETRE);
  vitesse = (potar*vmax)/1023;
  Serial.println("vitesse supposé");
  Serial.println(vitesse);
  Serial.println("potar=");
  Serial.println(potar);
  md.setM1Speed(vitesse);
  stopIfFault();
  delay(2);
}
