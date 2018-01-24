# Robot qui souffre

[évoqué ici](../textes/anthropomorphisme.md)

## Esthétique, allure du robot

Une boite en carton. Simple.
C'est tout...
Une simple boite en carton.

## Matériaux envisagés

- Du carton
- Un module arduino
- Un micro contact
- Un haut parleur

###Modularité
- il y a une sortie son, si on veut le brancher sur autre chose que le haut parleur intégré
- il y a une entrée qui doit etre un signal standard du spectacle et qui signifie "on me frappe à telle intensité"

## Moment envisagé pour la construction
Usinotopie mars 2018

## Hypothèses de construction, description technique

Voila un exemple de code Arduino qui allume une led quant un piezzo capte un coup dont l'intensité dépasse une valeur seuil. Très facilement modifiable (j'ai commenté les 2 endroits où il faudra faire des petites modifs) afin de lire des enregistrements de cris qui soient "proportionnels" au coup détecté.

/* Knock Sensor

   This sketch reads a piezo element to detect a knocking sound.
   It reads an analog pin and compares the result to a set threshold.
   If the result is greater than the threshold, it writes
   "knock" to the serial port, and toggles the LED on pin 13.

   The circuit:
	* + connection of the piezo attached to analog in 0
	* - connection of the piezo attached to ground
	* 1-megohm resistor attached from analog in 0 to ground

   http://www.arduino.cc/en/Tutorial/Knock

   created 25 Mar 2007
   by David Cuartielles <http://www.0j0.org>
   modified 30 Aug 2011
   by Tom Igoe

   This example code is in the public domain.


// these constants won't change:
const int ledPin = 13;      // led connected to digital pin 13

const int knockSensor = A0; // the piezo is connected to analog pin 0

const int threshold = 100;  // threshold value to decide when the detected sound is a knock or not



// these variables will change:
int sensorReading = 0;      // variable to store the value read from the sensor pin
int ledState = LOW;         // variable used to store the last LED status, to toggle the light


void setup() {
  pinMode(ledPin, OUTPUT); // declare the ledPin as as OUTPUT
  Serial.begin(9600);       // use the serial port
}

void loop() {
  // read the sensor and store it in the variable sensorReading:
  sensorReading = analogRead(knockSensor);

  // if the sensor reading is greater than the threshold:
  
  //Ici on peut imaginer plusieurs conditions if, chacune correspondant à une gamme d'intensités différente qui joueraient des enregistrements de cris de plus en plus forts.
  
  if (sensorReading >= threshold) {
    // toggle the status of the ledPin:
    //Ici modifier pour lire l'échantillon lié à l'intensité détectée
    ledState = !ledState;
    // update the LED pin itself:
    digitalWrite(ledPin, ledState);
    // send the string "Knock!" back to the computer, followed by newline
    Serial.println("Knock!");
  }
  delay(100);  // delay to avoid overloading the serial port buffer
}



