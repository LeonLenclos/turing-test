// cable vert = trig du capteur port digital 2
const char DOUT_TRIGGER = 2;
// cable bleu port digital 5
const char DIN_ECHO = 5;
// LED branché à la sortie digitale 4
const int LEDPIN = 4;
// port potentiometre: A0
const int PORTPOTENTIOMETRE = A0;

// A1 est en l'air car il définit la graine du générateur aléatoire


// nbre de détections avant lecture
const int compteurMax = 6;


//distance de déclenchement en centimètres
const int distanceSeuil = 70;


float distance;
int nbDuFichierChoisi;
int compteurAbsent = 0;
int compteurPresent = 0;
bool objetPresent = false;
char fileName[8] = "echo1";

#include <SPI.h>
#include <Adafruit_VS1053.h>
#include <SD.h>

// define the pins used
//#define CLK 13       // SPI Clock, shared with SD card
//#define MISO 12      // Input data, from VS1053/SD card
//#define MOSI 11      // Output data, to VS1053/SD card
// Connect CLK, MISO and MOSI to hardware SPI pins. 
// See http://arduino.cc/en/Reference/SPI "Connections"
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
Adafruit_VS1053_FilePlayer musicPlayer = 
  // create breakout-example object!
  //Adafruit_VS1053_FilePlayer(BREAKOUT_RESET, BREAKOUT_CS, BREAKOUT_DCS, DREQ, CARDCS);
  // create shield-example object!
  Adafruit_VS1053_FilePlayer(SHIELD_RESET, SHIELD_CS, SHIELD_DCS, DREQ, CARDCS);




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

  // Timer interrupts are not suggested, better to use DREQ interrupt!
  //musicPlayer.useInterrupt(VS1053_FILEPLAYER_TIMER0_INT); // timer int

  // If DREQ is on an interrupt pin (on uno, #2 or #3) we can do background
  // audio playing
  musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT);  // DREQ int
   // Play one file, don't return until complete
 
  
    pinMode(DOUT_TRIGGER, OUTPUT);
    pinMode(DIN_ECHO, INPUT);
    // musicPlayer.playFullFile("echo1.wav");
    pinMode(3, OUTPUT);
    digitalWrite(3, HIGH);
  }


  
void loop()
  { //  lecture potar
    //  potar = analogRead(A0);
    digitalWrite(DOUT_TRIGGER, LOW);
    delayMicroseconds(2);
    digitalWrite(DOUT_TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(DOUT_TRIGGER, LOW);
    
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
     
     /*Serial.println("potar =");
    Serial.println(potar);*/
    
    if (distance < distanceSeuil) {
      if (objetPresent == false) {
        if (compteurPresent < compteurMax){
          compteurPresent += 1;
        }
        else { objetPresent = true;
          nbDuFichierChoisi = random(1,13);
          //Serial.println(nbDuFichierChoisi);
          digitalWrite(LEDPIN, LOW);
          sprintf(fileName, "ECHO%d.mp3", nbDuFichierChoisi);
          // Play one file, don't return until complete
          musicPlayer.playFullFile(fileName);  
          //Serial.println(fileName);
          compteurPresent = 0;   }     
        }
    }
  
    
    if (distance >= distanceSeuil){
      if (objetPresent == true) {
        if (compteurAbsent < compteurMax){
          compteurAbsent += 1;
        }
        else { 
          objetPresent = false;
          digitalWrite(LEDPIN, HIGH);
          compteurAbsent = 0; 
          }     
        }
    delay(20);}
  }
