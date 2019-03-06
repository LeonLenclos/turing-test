// cable vert = trig du capteur port digital 2
const char DOUT_TRIGGER = 2;
// cable bleu port digital 5
const char DIN_ECHO = 5;
// LED branché à la sortie digitale 4
const int LEDPIN = 13;
// port potentiometre exigence: A0
const int PORTPOTENTIOMETRE = A0;
// port entrée jack trigger audio: 
const int TRIGPIN = 7;
// Sortie PWM vumetre
const int VUMETRE = 4;

// A1 est en l'air car il définit la graine du générateur aléatoire

//niveau max de la sortie PWM vers le vumetre, c'est la tension minimale telle que l'aiguille soit à fond. Entre 0(0V) et 255(5V)
const int calibrageVumetre = 255;
//nbre de fichiers Jaime et Jaimepas
const int nbDeFichiersJaime = 7;

//nbre de fichiers Jaime et Jaimepas
const int nbDeFichiersJaimePas = 5;

// nbre de détections avant de considérer qu'un objet est absent
const int compteurMaxAbsent = 6;

// nbre de détections avant de considérer qu'un objet est present
const int compteurMaxPresent = 6;


//distance de déclenchement en centimètres
const int distanceSeuil = 70;


int trigState = LOW;
float distance;
int nbDuFichierChoisi;
int aleat;
int exigence;
int compteur = 0;
bool objetPresent = false;
char fileName[8] = "echo1";

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

  // list files
  // printDirectory(SD.open("/"), 0);
  
  // Set volume for left, right channels. lower numbers == louder volume!
  musicPlayer.setVolume(0,0);

  // If DREQ is on an interrupt pin (on uno, #2 or #3) we can do background
  // audio playing
  musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT);
 
  
    pinMode(DOUT_TRIGGER, OUTPUT);
    pinMode(DIN_ECHO, INPUT);
    pinMode(TRIGPIN, INPUT);
    
    pinMode(LEDPIN, OUTPUT);
    //La LED clignote 2 fois à l'initialisation
    digitalWrite(LEDPIN, HIGH);
    delay(400);
    digitalWrite(LEDPIN, LOW);
    delay(400);
    digitalWrite(LEDPIN, HIGH);
    delay(400);
    digitalWrite(LEDPIN, LOW);
  }


  
void loop()
  {
    aleat = random(0,1023);
    
    //  lecture potar (entre 0 et 1023)
    exigence = analogRead(PORTPOTENTIOMETRE);
    /*Serial.println("potar =");
    Serial.println(potar);*/

 
      
    if (aleat < exigence)
      {
        nbDuFichierChoisi = random(0,nbDeFichiersJaime);
        sprintf(fileName, "JAIME0%d.mp3", nbDuFichierChoisi);  
      }
    else
      {
        nbDuFichierChoisi = random(0,nbDeFichiersJaimePas);
        sprintf(fileName, "JAIMEPAS0%d.mp3", nbDuFichierChoisi);  
      }
    //Serial.println(nbDuFichierChoisi);
    
    // On lit l'etat du trig audio:
    trigState = digitalRead(TRIGPIN);

    if (trigState == HIGH) {
      digitalWrite(LEDPIN, HIGH);
      // Play one file, don't return until complete
      musicPlayer.playFullFile(fileName); 
      digitalWrite(LEDPIN, LOW);
    }
    else {
      //On envoie une très courte impulsion d'ultrasons
      digitalWrite(DOUT_TRIGGER, LOW);
      delayMicroseconds(2);
      digitalWrite(DOUT_TRIGGER, HIGH);
      delayMicroseconds(10);
      digitalWrite(DOUT_TRIGGER, LOW);
      //La distance est déduite du temps qu'a mis l'écho de l'impulsion à être reçue par le capteur
      distance= pulseIn(DIN_ECHO, HIGH) / 58.0;
       
      /*
       Serial.print("distance =");
       Serial.println(distance);
       Serial.print("compteur present =");
       Serial.println(compteurPresent);
       Serial.print("compteur absent =");
       Serial.println(compteurAbsent);
       Serial.print("objet present =");
       Serial.println(objetPresent);
       */
       
      
      if (distance < distanceSeuil) {
        //Le vumetre affiche la distance de l'objet au robot
        analogWrite(VUMETRE, calibrageVumetre-((distanceSeuil-distance)*(calibrageVumetre/distanceSeuil)));
        //analogWrite(VUMETRE, calibrageVumetre-log((distanceSeuil-distance)*(calibrageVumetre/distanceSeuil)));
        if (objetPresent == false) {
          if (compteur < compteurMaxPresent){
            compteur += 1;
          }
          else {
            objetPresent = true;
            digitalWrite(LEDPIN, HIGH);
            compteur = 0;
            // Play one file, don't return until complete
            musicPlayer.playFullFile(fileName);  
            }     
          }
      }
    
      
      if (distance >= distanceSeuil){
        //Le vumetre affiche sa valeur max
        analogWrite(VUMETRE, calibrageVumetre);
        if (objetPresent == true) {
          if (compteur < compteurMaxAbsent){
            compteur += 1;
          }
          else { 
            objetPresent = false;
            compteur = 0;
            digitalWrite(LEDPIN, LOW);
            }     
          }
      delay(20);}
    }
  }
