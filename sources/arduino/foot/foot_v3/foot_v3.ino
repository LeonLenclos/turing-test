///////////// REGLAGES
const int seuilFaible = 4; 
const int seuilMedium = 18;
const int seuilFort = 55;
const int attente = 100; //attente entre la détection et la lecture audio (pour éviter que le son du choc interfère avec le cri de foot)
const int tempsRedeclenchement = 500;
const long tempsDemarrage = 10; //Temps d'attente avant démarrage (lancement de void loop) en secondes

//////////// PINS
const int LEDPIN = 2;
const int PIEZZO1 = A0; 
const int PIEZZO2 = A2; 
const int PIEZZO3 = A4; 
// A3 est en l'air car il définit la graine du générateur aléatoire

/////////////////// VAR
//nmbre de characteres max dans le nom d'un fichier (ne pas dépasser 12 car le shield ne gère pas les fichiers au nom trop long)
char fileName[8];

int amplitudeDetectee = 0; 

//////////////// ADAFRUIT INIT
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

//////////////////// SETUP
void setup() {
  Serial.begin(9600);
  Serial.println(F("Start setup"));
  
  // begin random
  randomSeed(analogRead(3));
  
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
  pinMode(LEDPIN, OUTPUT);
  
  // La LED clignote 2 fois à l'initialisation
  digitalWrite(LEDPIN, LOW);
  for (int i = 0; i < tempsDemarrage; i++) {
    Serial.println(F("blink !"));
    delay(500); digitalWrite(LEDPIN, LOW);
    delay(500); digitalWrite(LEDPIN, HIGH);
  }
  
  Serial.println(F("Setup done"));

}


//////////////////// LOOP //////////////////////////////////////////////
void loop() {

  //amplitueDetectee est le max des amplitudes detectees par les 3 piezzos
  int piezo1=analogRead(PIEZZO1);
  int piezo2=analogRead(PIEZZO2);
  int piezo3=analogRead(PIEZZO3);
  amplitudeDetectee = max(max(piezo1,piezo2),piezo3);

  // debug
  char debug[50];
  sprintf(debug, "amp=%04d piezzo1=%04d piezzo2=%04d piezzo3=%04d",amplitudeDetectee, piezo1,piezo2,piezo3);
  Serial.println(debug);
  
  // if the sensor reading is greater than the threshold:
 /* if (amplitudeDetectee >= seuilFaible ){
    // Serial.println("Knock!");
  
    if (amplitudeDetectee <= seuilMedium) {
      sprintf(fileName, "SOFT%d.mp3", random(0,9)); 
    }  
    else if ((amplitudeDetectee >= seuilMedium )&&(amplitudeDetectee<= seuilFort) ) {
      sprintf(fileName, "MEDI%d.mp3", random(0,9));  
    } 
    else if (amplitudeDetectee >= seuilFort ) {
      sprintf(fileName, "HARL%d.mp3", random(0,9));      
    }    
    delay(attente);
    musicPlayer.playFullFile(fileName);
    //Serial.println(fileName);
    delay(tempsRedeclenchement);
     
  } */
 
    delay(30);   
}
