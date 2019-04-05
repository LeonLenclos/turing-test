#include <IRremote.h>


//////////// PINS
const int RECV_PIN = 2;

/////////////////// VAR
bool moteur_On = false;
int vitesse;

////// INIT TELECOMMANDE
IRrecv irrecv(RECV_PIN);
decode_results results;
////// INIT SERVO
Servo myservo;  // Créer un objet servo



//////////////////// SETUP
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Initialise le recepteur
  myservo.attach(9, 244, 5400); //Attache le servo (en fait l'ESC) au port 9
  vitesse = vitesse_Initiale; //entre 90 et 180 multiple de 10 de preference
  
 

}



void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value); //affiche les données de la telecommande
    irrecv.resume(); // Recoit la valeur suivante
  }
  delay(4);
}
