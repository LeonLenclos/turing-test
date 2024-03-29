#include <Servo.h>
 
 
// Déclaration des ports (pins) des entrées sorties
const int buttonPin = 2;
const int trigPin = 4;
const int ledPin =  13;
const int ServoPin = 9;
//delai en ms ajouté à la fin de la boucle pour éviter de rendre fou l'arduino
const int delai = 20;

//Débatement: Angle parcouru pour chaque coup de médiator 
const int debatement = 15; 
//tempo en ms
const int tempo = 1500;
const int positionCorde = 88;


// Initialisation des entrées sorties
int positionServo;
int buttonState = LOW;
int trigState = LOW;
int potarActuel;
int potarPreced;
int randNumber;
//temps écoulé depuis l'allumage de l'arduino
long temps = 0;
// buttonStatePreced est la valeur binaire du bouton à la boucle précédente
bool buttonStatePreced = false;
bool sequenceState = false;
bool allerretour=true;
// création de l'objet moteur
Servo moteur;

void coupdemediator()
{
  if (allerretour == true) {
       Serial.print("\n A vraie"); 
       digitalWrite(ledPin, HIGH);
        
        positionServo = min(positionCorde+debatement,180);
        moteur.write(positionServo);
        
        allerretour = false; 
        Serial.print("\n A faux");
        digitalWrite(ledPin, LOW);

      }
      
  else {
    Serial.print("\n B faux"); 
        digitalWrite(ledPin, HIGH);
        positionServo = max(positionCorde-debatement,0);
        moteur.write(positionServo);
        allerretour = true; 
       Serial.print("\n B vraie");  
        digitalWrite(ledPin, LOW);
        
      }
}


//Proframme d'intialisation (lu une fois au démarage et si on appuie sur reset)
void setup() {
 

  //déclaration des entrées sorties
  pinMode(buttonPin, INPUT);
  pinMode(trigPin, INPUT);
  pinMode(ledPin, OUTPUT);
  moteur.attach(ServoPin);
  
  //La LED clignote 2 fois à l'initialisation  
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  
  //On acquiert la valeur du potar
  potarActuel = analogRead(A0);
  potarPreced=potarActuel;
  //On initialise la position du moteur à la position initiale du potar
  positionServo = positionCorde-debatement;
  moteur.write(positionServo);
  // On initialise la graine du générateur de nombres aleatoires en mesurant le bruit d'une entrée vide, ici A1
  randomSeed(analogRead(A1));  

  Serial.begin(9600);


}

void loop() {
 /* Affichage moniteur série pour débuggage 
 Serial.print("\n potarActuel ");
    Serial.print(potarActuel);
  Serial.print(allerretour);*/
  
  /////////////////////////////////////////////REGLAGE MOTEUR PAR POTAR///////////////////////////////////
  /*
  //lire valeur potentiometre
  potarActuel = analogRead(A0);
  //si ecart suffisant bouger moteur en fctn de potentiometre
  
  if(abs(potarActuel-potarPreced)>10)
  {
   positionServo = map(potarActuel, 0, 1023, 0, 180);
   moteur.write(positionServo);
   potarPreced=potarActuel;
    }
    */
////////////////////////////////////////////SEQUENCES IMPRO //////////////////////////////////////////////

  // lire l'etat du bouton:
  buttonState = digitalRead(buttonPin);
  //Activer séquence et allumer led si bouton appuye et bouton précédent pas appuyé:
  if ((buttonState == HIGH) && (buttonStatePreced == false)) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    buttonStatePreced = true;
    //Activer ou désactiver séquence
    sequenceState = !sequenceState;
  }
  
  // Sinon:
  else {
    //Si bouton pas appuyé
    if (buttonState == LOW){
    
    // turn LED off:
    digitalWrite(ledPin, LOW);
    buttonStatePreced = false;
        }
      }
   if (sequenceState == true) {  
     //générer un nombre aléatoire 0, 1 ou 2: 0 Jimi ne joue pas, 1 il joue une note, 2 il joue un aller retour
     randNumber = random(3);  
     // on regarde le temps auquel on déclenche le moteur du médiator
     if ((millis()-temps) >= tempo) {
       temps = millis();
       if (randNumber == 1){ 
         Serial.print("\n parti");
         coupdemediator();
         Serial.print("\n fini");
       }
       if (randNumber == 2){
        Serial.print("\n parti"); 
          coupdemediator ();
          Serial.print("\n fini");
          delay(1);
          Serial.print("\n parti");
          coupdemediator ();
          Serial.print("\n fini");
        }
     }
   }
        
////////////////////////////////////////////////////////// TRIG /////////////////////////////////////////////////////////
  // lire l'etat du trig:
  trigState = digitalRead(trigPin);
  //jouer un coup de mediator si trig recu
  if (trigState == HIGH) {
    Serial.print("\n parti"); 
    coupdemediator();   
   Serial.print("       fini"); 
  }

  delay(delai);
}

