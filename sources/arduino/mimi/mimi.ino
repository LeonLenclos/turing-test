#include <IRremote.h>
#include <Servo.h> 
 

///////////// REGLAGES
const int vitesse_Max = 180;
const int vitesse_Initiale = 100s;
const int pas_Incrementation_vitesse = 10;
// Messages Télécommande:
const long on_Off = 16761405; ////bouton play-pause
const long augmenter_vitesse = 16754775; //bouton +
const long diminuer_vitesse = 16769055; //bouton -
const long debut_init = 16738455; // bouton 0
//////////// PINS
const int RECV_PIN = 2; //Recepteur infrarouge telecommande
const int ESC_PIN = 9; //ESC drone

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
  myservo.attach(ESC_PIN, 244, 5400); //Attache le servo (en fait l'ESC) au port 9
  vitesse = vitesse_Initiale; //entre 90 et 180 multiple de 10 de preference
  
  //Initialisation de l'ESC a distance:
  bool init = false;
  while (!init){
    if (irrecv.decode(&results)) {
      if(results.value == debut_init){init= !init;}
    }
    delay(2);
  }
  delay(500);
  long int clock_Debut_Init = millis();
  //Code pour régler l'ESC
  Serial.println(F("Reglage ESC control max"));
  myservo.write(90);
  while(millis()<clock_Debut_Init+6000){
    if (irrecv.decode(&results)&&(results.value != debut_init)) {
      myservo.write(90);
      Serial.println(F("Reglage ESC avorté, vitesse baissée à 90"));
      
      delay(5000);
    }
  }
  
  Serial.println(F("Reglage ESC control min"));
  myservo.write(90);
  delay(3000);
  //delay(8000);

  Serial.println(F("Initialisation terminée"));

}



void loop() {
  if (irrecv.decode(&results)) {
    //Serial.println(results.value); //affiche les données de la telecommande
    
    if (results.value == on_Off) {
      moteur_On = !moteur_On;
      if (moteur_On) {
        myservo.write(vitesse);
        Serial.println(vitesse);
        }
      else {
        myservo.write(90);
        Serial.println(90);
        }
      }
      
      
    if (results.value == augmenter_vitesse) {
      if (moteur_On && (vitesse < vitesse_Max)){
        vitesse = vitesse + pas_Incrementation_vitesse;
        myservo.write(vitesse);
        Serial.println(vitesse);
        }
      }
      
      
    if (results.value == diminuer_vitesse) {
      if (moteur_On && (vitesse > 90)){
        vitesse = vitesse - pas_Incrementation_vitesse;
        myservo.write(vitesse);
        Serial.println(vitesse);
        }
      }
    irrecv.resume(); // Recoit la valeur suivante
  }
  delay(4);
}
