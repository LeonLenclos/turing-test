
///////////// REGLAGES
const int seuilFaible = 8; 
const int seuilMedium = 80;
const int seuilFort = 200;

//const int attente = 100; //attente entre la détection et la lecture audio (pour éviter que le son du choc interfère avec le cri de foot)
const int attente = 300;
//const int tempsRedeclenchement = 500;
const int tempsRedeclenchement = 100;
const long tempsDemarrage = 7; //Temps d'attente avant démarrage (lancement de void loop) en secondes


//////////// PINS
const int LEDPIN = 2;
const int PIEZZO1 = A0; 
//const int PIEZZO2 = A2; 
//const int PIEZZO3 = A4; 
// A3 est en l'air car il définit la graine du générateur aléatoire
const int TRIGPIN = 7; 

/////////////////// VAR

int aleat;
int trigState = LOW;
char debug[50];
char fileName[50];


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
  musicPlayer.GPIO_pinMode(TRIGPIN, INPUT);
  pinMode(LEDPIN, OUTPUT);
  
  // La LED clignote 2 fois à l'initialisation
  digitalWrite(LEDPIN, LOW);
  for (int i = 0; i < tempsDemarrage; i++) {
    Serial.println(F("blink !"));
    delay(500); digitalWrite(LEDPIN, LOW);
    delay(500); digitalWrite(LEDPIN, HIGH);
    
  }
  

}


//////////////////// LOOP //////////////////////////////////////////////
void loop() {
  delay(1);
  
  //amplitueDetectee est le max des amplitudes detectees par les 3 piezzos
  int piezzo1=analogRead(PIEZZO1);
  //int piezo2=analogRead(PIEZZO2);
  //int piezzo3=analogRead(PIEZZO3);
  //int moyenne = (piezzo1+piezzo3)/2;

  //int amplitudeDetectee = (max(piezzo1,piezzo3)+moyenne)/2;
  int amplitudeDetectee = piezzo1;
  // debug

  sprintf(debug, "amp=%04d piezzo1=%04d", amplitudeDetectee,piezzo1);

  Serial.println(debug);

  // if the sensor reading is greater than the threshold:

  if (amplitudeDetectee >= seuilFaible ){
     Serial.println("Knock!");
  
    
    if (amplitudeDetectee <= seuilMedium) {
      sprintf(fileName, "SOFT%d", random(0,9)); 
    }  
    else if ((amplitudeDetectee >= seuilMedium )&&(amplitudeDetectee <= seuilFort) ) {
      sprintf(fileName, "MEDI%d", random(0,9));  
    } 
    else if (amplitudeDetectee >= seuilFort ) {
      sprintf(fileName, "HARL%d", random(0,9));      
    }    
    delay(attente);
    strcat(fileName,".mp3");
    Serial.println(fileName);
    musicPlayer.playFullFile(fileName);
    Serial.println("joué");

    delay(tempsRedeclenchement);
     
  } 
  
  Serial.println(F("trig :"));
  Serial.println(musicPlayer.GPIO_digitalRead(TRIGPIN));
  Serial.println(trigState);

  if (musicPlayer.GPIO_digitalRead(TRIGPIN) != trigState) {
    trigState = !trigState;
    if (trigState == HIGH) {
      Serial.println(F("trig detecté"));
      sprintf(fileName, "SOFT%d", random(0,9)); 
      strcat(fileName,".mp3");
      Serial.println(fileName);
      musicPlayer.playFullFile(fileName);
      Serial.println("joué");}
     }
  }
