#include <IRremote.h>
#include <Servo.h> 
 

///////////// REGLAGES
const int vitesse_Max = 180;
const int temps_Suicide = 500;// en millisecondes
const int vitesse_Initiale = 95;
const int pas_Incrementation_vitesse = 5;
// Messages Télécommande:
const long play = 284117940; ////bouton play >|
const long pause = 284152110; ////bouton stop []
const long augmenter_vitesse = 284101620; //bouton >>
const long diminuer_vitesse = 284134260; //bouton <<
const long init_Esc = 284158740; // bouton Standby
const long demarrer_beug = 284099580; // bouton sleep
const long mode_0 = 284138340;
const long mode_1 = 284129670;
const long mode_2 = 284137830;
const long mode_3 = 284145990;
const long mode_4 = 284126100;
const long mode_5 = 284122020;
const long mode_6 = 284130180;
const long mode_7 = 284125590;
const long mode_8 = 284121510;
const long mode_9 = 284129670;



//////////// PINS
const int RECV_PIN = 10; //Recepteur infrarouge telecommande
const int ESC_PIN = 9; //ESC drone

/////////////////// VAR
bool moteur_On = false;
int vitesse;
int duree_Allumage = 1000;
long int clock_Extinction_Automatique;

////// INIT TELECOMMANDE
IRrecv irrecv(RECV_PIN);
decode_results results;
////// INIT SERVO
Servo myservo;  // Créer un objet servo

//////////////////// Functions
void changer_vitesse_moteur(int vitesse_moteur){
   if (moteur_On){
      clock_Extinction_Automatique = millis();
      myservo.write(vitesse_moteur);
      Serial.println(vitesse_moteur);
   }
}

void eteindre_moteur(){
      moteur_On = false;
      myservo.write(90);
      Serial.println(F("moteur eteint"));
   }


void suicide(){
  Serial.println(F("suicide"));
  moteur_On = true;
  changer_vitesse_moteur(105);
  delay(500);
  eteindre_moteur();
  delay(500);
  
   }

void beug(){
  Serial.println(F("beug"));
  for (int i = 0; i <= 2; i++) {
    moteur_On = true;
    changer_vitesse_moteur(95);
    delay(500);
    changer_vitesse_moteur(110);
    delay(500);
    moteur_On = false;
    eteindre_moteur();
    delay(500);
    }
   }

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
      if(results.value == init_Esc){init= !init; }
    }
    delay(2);
  }
  delay(500);
  clock_Extinction_Automatique = millis();
  //Code pour régler l'ESC
  Serial.println(F("Reglage ESC control max"));
  myservo.write(90);
  while(millis()<clock_Extinction_Automatique+6000){
    if (irrecv.decode(&results)&&(results.value != init_Esc)) {
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

//////////////////// LOOP ////////////////////////////////////////////

void loop() {
  if (millis() > clock_Extinction_Automatique + 3000) {
    if(moteur_On){
      Serial.println("extinction automatique");
      eteindre_moteur();
       }
    }
  
  if (irrecv.decode(&results)) {
    //Serial.println(results.value); //affiche les données de la telecommande

    if (results.value == mode_0) {
      eteindre_moteur();
      }
      
    if (results.value == mode_1) {
      moteur_On = true;
      vitesse = 100;
      changer_vitesse_moteur(vitesse);
      }

    if (results.value == mode_2) {
      moteur_On = true;
      vitesse = 110;
      changer_vitesse_moteur(vitesse);
      }

    if (results.value == mode_3) {
      moteur_On = true;
      vitesse = 120;
      changer_vitesse_moteur(vitesse);
      }

     if (results.value == mode_4) {
      moteur_On = true;
      vitesse = 130;
      changer_vitesse_moteur(vitesse);
      }

    if (results.value == mode_5) {
      moteur_On = true;
      vitesse = 140;
      changer_vitesse_moteur(vitesse);
      }

    if (results.value == mode_6) {
      moteur_On = true;
      vitesse = 150;
      changer_vitesse_moteur(vitesse);
      }

    if (results.value == mode_7) {
      moteur_On = true;
      vitesse = 160;
      changer_vitesse_moteur(vitesse);
      }

    if (results.value == mode_8) {
      moteur_On = true;
      vitesse = 170;
      changer_vitesse_moteur(vitesse);
      }
    if (results.value == mode_9) {
      moteur_On = true;
      changer_vitesse_moteur(180);
      }

      if (results.value == demarrer_beug) {
      beug();
      }
     
    if (results.value == play) {
      moteur_On = true;
      clock_Extinction_Automatique = millis();
      myservo.write(vitesse);
      Serial.println(vitesse);
      }
      
    if (results.value == pause) {
      eteindre_moteur();
      }

    if ((results.value == augmenter_vitesse)&&((vitesse + pas_Incrementation_vitesse) < vitesse_Max)) {
      vitesse = vitesse + pas_Incrementation_vitesse;
      changer_vitesse_moteur(vitesse);
      } 
    if ((results.value == diminuer_vitesse)&&((vitesse - pas_Incrementation_vitesse) > 90)) {
      vitesse = vitesse - pas_Incrementation_vitesse;
      changer_vitesse_moteur(vitesse);
      }
      
   /*
      if (results.value == demarrer_suicide) {
      suicide();
      }
  */  
    irrecv.resume(); // Recoit la valeur suivante
  }
  delay(2);
}
