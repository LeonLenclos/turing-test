// include SPI, MP3 and SD libraries
const int ledPin = 13;      // led connected to digital pin 13
const int piezo = A0; // the piezo is connected to analog pin 0
const int seuilFaible = 4; 
const int seuilMedium = 18;
const int seuilFort = 55;
const int attente = 150;
const int tempsRedeclenchement = 500;
int nbfichier = 0;
int longoucourt = 0;
char fileName[8];

int sensorReading = 0; 
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
#define BREAKOUT_DCS    8      // VS1053 Data/command select pin (output)
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

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(1));
  
  if (! musicPlayer.begin()) { // initialise the music player
 //    Serial.println(F("Couldn't find VS1053, do you have the right pins defined?"));
     while (1);
  }
 // Serial.println(F("VS1053 found"));
  
   if (!SD.begin(CARDCS)) {
//    Serial.println(F("SD failed, or not present"));
    while (1);  // don't do anything more
  }

 //  list files
 //  printDirectory(SD.open("/"), 0);
  
  // Set volume for left, right channels. lower numbers == louder volume!
  musicPlayer.setVolume(0,0);

  // Timer interrupts are not suggested, better to use DREQ interrupt!
  //musicPlayer.useInterrupt(VS1053_FILEPLAYER_TIMER0_INT); // timer int

  // If DREQ is on an interrupt pin (on uno, #2 or #3) we can do background
  // audio playing
  musicPlayer.useInterrupt(VS1053_FILEPLAYER_PIN_INT);  // DREQ int
    delay(90000);
  
}

void loop() {

 
  sensorReading = analogRead(piezo);
  Serial.println(sensorReading);
 

 
  // if the sensor reading is greater than the threshold:
  if (sensorReading >= seuilFaible ){
    
  
    if ((sensorReading <= seuilMedium) ) {
      nbfichier = random(0,9);
      sprintf(fileName, "SOFT%d.mp3", nbfichier);
     
      
      Serial.println(fileName);   
    }  
     if ((sensorReading >= seuilMedium )&&(sensorReading<= seuilFort) ) {
    // Serial.println("Knock!");
      nbfichier = random(0,9);
      sprintf(fileName, "MEDI%d.mp3", nbfichier);
     
      
      Serial.println(fileName);
      delay(tempsRedeclenchement);   
    } 
     if (sensorReading >= seuilFort ) {
      // longoucourt = random(0,2);

    
      if (longoucourt) {

      nbfichier = random(0,9);
      sprintf(fileName, "HARL%d.mp3", nbfichier);     
      }
      else {
      nbfichier = random(0,14);
      sprintf(fileName, "HARL%d.mp3", nbfichier);
      }  
    }
    
    delay(attente);
    musicPlayer.playFullFile(fileName); 
    Serial.println(fileName);
    delay(tempsRedeclenchement);
     
  } 
 
    delay(50);
    
}
