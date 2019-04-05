#include <IRremote.h>


//////////// PINS
const int RECV_PIN = 2;


////// INIT TELECOMMANDE
IRrecv irrecv(RECV_PIN);
decode_results results;

//////////////////// SETUP
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Initialise le recepteur
  

}



void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value); //affiche les données de la telecommande
    irrecv.resume(); // Recoit la valeur suivante
  }
  delay(4);
}
