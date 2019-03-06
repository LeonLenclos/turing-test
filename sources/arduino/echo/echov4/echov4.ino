// cable vert = trig du capteur port GPIO 2
const char DOUT_TRIGGER = 2;
// cable bleu port Digitale 5;
const char DIN_ECHO = 5;
// LED branché à la sortie GPIO1 du shield
const int LEDPIN = 1;
// port potentiometre exigence: A0
const int PORTPOTENTIOMETRE = A0;
// port entrée jack trigger audio: 
const int TRIGPIN = 11;
// Sortie PWM vumetre
const int VUMETRE = 4;

// A1 est en l'air car il définit la graine du générateur aléatoire

//niveau max de la sortie PWM vers le vumetre, c'est la tension minimale telle que l'aiguille soit à fond. Entre 0(0V) et 255(5V)
const int CALIBRAGE_VUMETRE = 255;
//nbre de fichiers Jaime et Jaimepas
const int NB_FICHIERS_JAIME = 7;
const int NB_FICHIERS_JAIMEPAS = 5;
// nbre de détections avant de considérer qu'un objet est absent ou present
const int COMPTEUR_MAX_ABSENT = 75;
const int COMPTEUR_MAX_PRESENT = 10;
//distance de déclenchement en centimètres
const int DISTANCE_SEUIL = 70;


long chrono;
int trigState = LOW;
float distance;
int nbDuFichierChoisi = 1;
int aleat;
int exigence;
int compteur = 0;
bool objetPresent = false;
// 14 est le nmbre de characteres max dans le nom d'un fichier
char fileName[15] = "echo1";

#include <SPI.h>
#include <Adafruit_VS1053.h>
#include <SD.h>

// define the pins used
// These are the pins used for the breakout example
#define BREAKOUT_RESET  9      // VS1053 reset pin (output)
#define BREAKOUT_CS     10     // VS1053 chip select pin (output)
#define BREAKOUT_DCS    8      // VS1053 Data/command select pin (output)f
// These are the pins used for the music maker shield
#define SHIELD_RESET  -1      // VS1053 reset pin (unused!)
#define SHIELD_CS     7      // VS1053 chip select pin (output)
#define SHIELD_DCS    6      // VS1053 Data/command select pin (output)
// These are common pins between breakout and shield
#define CARDCS 4     // Card chip select pin
// DREQ should be an Int pin, see http://arduino.cc/en/Reference/attachInterrupt
#define DREQ 3       // VS1053 Data request, ideally an Interrupt pin
Adafruit_VS1053_FilePlayer musicPlayer = Adafruit_VS1053_FilePlayer(SHIELD_RESET, SHIELD_CS, SHIELD_DCS, DREQ, CARDCS);




void setup()
  {
  Serial.begin(9600);
  randomSeed(analogRead(1));
  
  if (! musicPlayer.begin()) { // initialise the music player
     Serial.println(F("Couldn't find VS1053, do you have the right pins defined?"));
     while (1);
  }
  
  Serial.println(F("VS1053 found"));
  
   if (!SD.begin(CARDCS)) {
    Serial.println(F("SD failed, or not present"));
    while (1);  // don't do anything more
  }

  Serial.println(F("SD card found"));

  // Set volume for left, right channels. lower numbers == louder volume!
  musicPlayer.setVolume(0,0);

  // If DREQ is on an interrupt pin (on uno, #2 or #3) we can do background
  // audio playing
  musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT);


    musicPlayer.GPIO_pinMode(LEDPIN, OUTPUT);
    musicPlayer.GPIO_pinMode(DOUT_TRIGGER, OUTPUT);
    musicPlayer.GPIO_digitalWrite(DOUT_TRIGGER, LOW);
    pinMode(DIN_ECHO, INPUT);
    musicPlayer.GPIO_pinMode(TRIGPIN, INPUT);
    
    //La LED clignote 2 fois à l'initialisation
    //digitalWrite(LEDPIN, LOW);
    /*
    delay(2000);
    digitalWrite(LEDPIN, HIGH);
    delay(2000);
    digitalWrite(LEDPIN, LOW);
    delay(2000);
    digitalWrite(LEDPIN, HIGH);
    delay(2000);
    digitalWrite(LEDPIN, LOW);
*/
 
   
    

  }

void playSample() {

      // Play one file, don't return until complete
      //digitalWrite(LEDPIN, HIGH);
      musicPlayer.GPIO_digitalWrite(LEDPIN, LOW);
      musicPlayer.playFullFile("JAIME00.mp3"); 
      //digitalWrite(LEDPIN, LOW);
}

int distanceObjet() {
      musicPlayer.GPIO_digitalWrite(DOUT_TRIGGER, LOW);
      delayMicroseconds(2);
      musicPlayer.GPIO_digitalWrite(DOUT_TRIGGER, HIGH);
      delayMicroseconds(10);
      musicPlayer.GPIO_digitalWrite(DOUT_TRIGGER, LOW);
      return pulseIn(DIN_ECHO, HIGH) / 58.0;
}


void loop()
  {
    delay(20);
    aleat = random(0,1023);
    
    //  lecture potar (entre 0 et 1023)
  //  exigence = analogRead(PORTPOTENTIOMETRE);
    /*Serial.println("potar =");
    Serial.println(potar);*/

 
   /*   
    if (aleat < exigence)
      {
        nbDuFichierChoisi = random(0,NB_FICHIERS_JAIME);
        sprintf(fileName, "JAIME0%d.mp3", nbDuFichierChoisi);  
      }
    else
      {
        nbDuFichierChoisi = random(0,NB_FICHIERS_JAIMEPAS);
        sprintf(fileName, "JAIMEPAS0%d.mp3", nbDuFichierChoisi);  
      }
    //Serial.println(nbDuFichierChoisi);
    */
    
   //sprintf(fileName, "JAIMEPAS0%d.mp3", nbDuFichierChoisi);
         //Serial.println(fileName);
   
    // On lit l'etat du trig audio:
   // trigState = digitalRead(TRIGPIN);

    if (trigState == HIGH && false) {
      playSample();
    }
    else {
      //On envoie une très courte impulsion d'ultrasons
      
       distance = distanceObjet();
       Serial.println(distance);
      /*
       Serial.print("distance =");
       Serial.println(distance);
       Serial.print("compteur =");
       Serial.println(compteur);
       Serial.print("objet present =");
       Serial.println(objetPresent);
      */
       
      compteur += 1;
      if (distance < DISTANCE_SEUIL && objetPresent == false && compteur > COMPTEUR_MAX_PRESENT) {
        //Le vumetre affiche la distance de l'objet au robot
        //analogWrite(VUMETRE, CALIBRAGE_VUMETRE-((DISTANCE_SEUIL-distance)*(CALIBRAGE_VUMETRE/DISTANCE_SEUIL)));
        //analogWrite(VUMETRE, CALIBRAGE_VUMETRE-log((DISTANCE_SEUIL-distance)*(CALIBRAGE_VUMETRE/DISTANCE_SEUIL)));    
        playSample();
        objetPresent = true;
        compteur = 0;
      }
      else if (distance >= DISTANCE_SEUIL && objetPresent == true && compteur > COMPTEUR_MAX_ABSENT){
        //Le vumetre affiche sa valeur max
        //analogWrite(VUMETRE, CALIBRAGE_VUMETRE);
            objetPresent = false;
            musicPlayer.GPIO_digitalWrite(LEDPIN, HIGH);
            compteur = 0;
      } 
          
      
     }
  }
