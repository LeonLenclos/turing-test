///////////// REGLAGES
//niveau max de la sortie PWM vers le vumetre, c'est la tension minimale telle que l'aiguille soit à fond. Entre 0(0V) et 255(5V)
const int CALIBRAGE_VUMETRE = 7;
const int NB_FICHIERS_JAIME = 7; //nbre de fichiers Jaime
const int NB_FICHIERS_JAIMEPAS = 5; //nbre de fichiers Jaimepas
const int COMPTEUR_MAX_ABSENT = 15; // nbre de détections avant de considérer qu'un objet est absent ou present
const int COMPTEUR_MAX_PRESENT = 10; //distance de déclenchement en centimètres
const int DISTANCE_SEUIL = 70; // en cm


//////////// PINS
const char DOUT_TRIGGER = 2; // port GPIO correspondant au détecteur d'ultrasons du capteur ultrason (cable vert);
const char DIN_ECHO = 5; // port digital correspondant au trig du capteur ultrason (cable bleu);
const int LEDPIN = 1; // port GPIO du shield correspondant à la LED
const int TRIGPIN = 3; // port digital correspondant à l'entrée jack trigger audio:
const int VUMETRE = 2; // Sortie PWM vumetre
const int PORTPOTENTIOMETRE = A0; // port potentiometre exigence: A0
// A1 est en l'air car il définit la graine du générateur aléatoire


//////////////// ADAFTUIT INIT
#include <SPI.h>
#include <Adafruit_VS1053.h>
#include <SD.h>
// define the pins used
#define SHIELD_RESET  -1      // VS1053 reset pin (unused!)
#define SHIELD_CS     7      // VS1053 chip select pin (output)
#define SHIELD_DCS    6     // VS1053 Data/command select pin (output)
#define CARDCS 4           // Card chip select pin
#define DREQ 3           // Card chip select pin
// Init music player
Adafruit_VS1053_FilePlayer musicPlayer = Adafruit_VS1053_FilePlayer(SHIELD_RESET, SHIELD_CS, SHIELD_DCS, DREQ, CARDCS);


/////////////////// VAR
int compteur = 0;
bool objetPresent = false;
//nmbre de characteres max dans le nom d'un fichier (ne pas dépasser 12 car le shield ne gère pas les fichiers au nom trop long)
char fileName[12] = "";



//////////////////// FUNCTIONS
// allumer eteindre led
void allumerLED() { musicPlayer.GPIO_digitalWrite(LEDPIN, LOW);}
void eteindreLED() { musicPlayer.GPIO_digitalWrite(LEDPIN, HIGH);}

// choisir et jouer un sample
void playSample() {
  int exigence = analogRead(PORTPOTENTIOMETRE); // Entre 0 et 691 car on est sur 3v, si connecté en 5v alors 0 et 1023
  char fileName[12] = ""; // Le shield exige max 12 char dans le nom du fichier
  if (random(0, 691) < exigence) {
    sprintf(fileName, "JAIME0%d.mp3", random(0, NB_FICHIERS_JAIME));
  } else {
    sprintf(fileName, "JEHAI0%d.mp3", random(0, NB_FICHIERS_JAIMEPAS));
  }
  musicPlayer.playFullFile(fileName);
}

// retourne la distance entre le capteur et l'objet
int distanceObjet() {
  musicPlayer.GPIO_digitalWrite(DOUT_TRIGGER, LOW);
  delayMicroseconds(2);
  musicPlayer.GPIO_digitalWrite(DOUT_TRIGGER, HIGH);
  delayMicroseconds(10);
  musicPlayer.GPIO_digitalWrite(DOUT_TRIGGER, LOW);
  return pulseIn(DIN_ECHO, HIGH) / 58.0;
}



//////////////////// SETUP
void setup() {
  Serial.begin(9600);
  Serial.println(F("Start setup"));
  
  // begin random
  randomSeed(analogRead(1));
  
  // begin music player
  if (! musicPlayer.begin()) { // initialise the music player
    Serial.println(F("Couldn't find VS1053, do you have the right pins defined?"));
    while (1);
  } Serial.println(F("VS1053 found"));
  
  // begin SD card
  if (!SD.begin(CARDCS)) {
    Serial.println(F("SD failed, or not present"));
    while (1);  // don't do anything more
  } Serial.println(F("SD card found"));
  
  // Set volume for left, right channels. lower numbers == louder volume!
  musicPlayer.setVolume(0, 0);
  
  // init pins
  musicPlayer.GPIO_pinMode(LEDPIN, OUTPUT);
  musicPlayer.GPIO_pinMode(DOUT_TRIGGER, OUTPUT);
  pinMode(DIN_ECHO, INPUT);
  pinMode(TRIGPIN, INPUT);

  // La LED clignote 2 fois à l'initialisation
  eteindreLED();
  for (int i = 0; i < 7; i++) {
    Serial.println(F("blink !"));
    delay(500); allumerLED();
    delay(500); eteindreLED();
  }
  
  Serial.println(F("Setup done"));
}


////////////////// LOOP
void loop()
{
  delay(20);
  //Si trig audio reçu, allumer led, jouer fichier audio puis éteindre led
  /*
  if (digitalRead(TRIGPIN) == HIGH) {
    allumerLED();
    //playSample();
    eteindreLED();
  }

  else {*/
    float distance = distanceObjet();
    Serial.println(distance);
    // minimum entre la distance à la distance seuil et la distance seuil en cm (entre 0 et DISTANCE_SEUIL)
    int distanceAffichee = DISTANCE_SEUIL - min(distance, DISTANCE_SEUIL);
    // On normalise entre 0 et le calibrage du vumetre
    distanceAffichee = distanceAffichee * CALIBRAGE_VUMETRE / DISTANCE_SEUIL;
    //Le vumetre affiche la distance de l'objet au robot
    analogWrite(VUMETRE, CALIBRAGE_VUMETRE - distanceAffichee);

    bool objetPresentTemp = (distance < DISTANCE_SEUIL);

    if (objetPresentTemp && !objetPresent) {
      compteur += 1;
      if (compteur > COMPTEUR_MAX_PRESENT) {
        allumerLED();
        playSample();
        objetPresent = true;
        compteur = 0;
      }
    }
    else if (!objetPresentTemp && objetPresent) {
      compteur += 1;
      if (compteur > COMPTEUR_MAX_ABSENT) {
        objetPresent = false;
        eteindreLED();
        compteur = 0;
      }
    }
    else {
      compteur = 0;
    }
  //}
}
