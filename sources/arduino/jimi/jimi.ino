#include <Stepper.h>

// Déclaration des ports (pins) des entrées sorties
const int buttonPin = 2;
const int trigPin = 4;
const int ledPin =  13;
//delai en ms ajouté à la fin de la boucle pour éviter de rendre fou l'arduino
const int delai = 1;
//nbre de pas du moteur:
const int nbredepas = 48*64;
//Débatement: nombre de pas parcourus pour chaque coup de médiator
const int debatement = 110;
//tempo en ms
const int tempo = 1300;
//compensation du décalage
const int comp= 0;

// Initialisation des entrées sorties
int buttonState = LOW;
int trigState = LOW;
int potarActuel;
int potarPreced;
int randNumber;
//temps écoulé depuis l'allumage de l'arduino
long temps;
// buttonStatePreced est la valeur binaire du bouton à la boucle précédente
bool buttonStatePreced = false;
bool sequenceState = false;
bool allerretour=true;


Stepper moteur(nbredepas,9,10,11,6);

//Proframme d'intialisation (lu une fois au démarage et si on appuie sur reset)
void setup() {
  //regler vitesse du moteur entre 0 et 10 tours par minute 
  moteur.setSpeed(9);
  //déclaration des entrées sorties
  pinMode(buttonPin, INPUT);
  pinMode(trigPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
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
  // On initialise la graine du générateur de nombres aleatoires en mesurant le bruit d'une entrée vide, ici A1
  randomSeed(analogRead(A1));
  // on initialise le temps
    temps = 0;
   

  Serial.begin(9600);


}

void loop() {
  //lire valeur potentiometre
  potarActuel = analogRead(A0);
 /* Affichage moniteur série pour débuggage 
 Serial.print("\n potarActuel ");
    Serial.print(potarActuel);
  Serial.print(allerretour);*/
  
  
  //si ecart suffisant bouger moteur en fctn de potentiometre
  if(abs(potarActuel-potarPreced)>10)
  {
   moteur.step(-2*(potarActuel-potarPreced));
   potarPreced=potarActuel;
    }
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
   //Faire un coup de médiator puis attendre 2 4 ou 6 temps avant de poursuivre le programme)
   if (sequenceState == true) {
     
     
     //générer un nombre aléatoire 0, 1 ou 2: 0 Jimi ne joue pas, 1 il joue une note, 2 il joue un aller retour
     randNumber = random(3);  
     // on regarde le temps auquel on déclenche le moteur du médiator
     if ((millis()-temps) >= tempo) {
       temps = millis();
       if (randNumber == 1){ 
         if (allerretour == true) {
        digitalWrite(ledPin, HIGH);
        moteur.step(debatement);
        digitalWrite(ledPin, LOW);
        allerretour = false;}
       else{
        digitalWrite(ledPin, HIGH);
        moteur.step(-(debatement+comp));
        digitalWrite(ledPin, LOW);
        allerretour = true;}
       }
       if (randNumber == 2){ 
          if (allerretour == true) {
            digitalWrite(ledPin, HIGH);
            moteur.step(debatement);
            delay(2);
            moteur.step(-(debatement+comp));
            digitalWrite(ledPin, LOW);
        }
       else{
        digitalWrite(ledPin, HIGH);
        moteur.step(-(debatement+comp));
        delay(2);
        moteur.step(debatement);
        digitalWrite(ledPin, LOW);}
         
       }
     }
   }
        

  // lire l'etat du trig:
  trigState = digitalRead(trigPin);
 
  //mettre moteur en marche et allumer led si trig recu
  if (trigState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    if (allerretour == true) {
      moteur.step(debatement);
      allerretour = false;
     }
     else
     {
      moteur.step(-(debatement+comp));
      allerretour = true;
     }
    
  }
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
  
  delay(delai);
}
