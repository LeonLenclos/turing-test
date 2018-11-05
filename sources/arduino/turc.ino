// Ports (pins) des entrées sorties
int Electroaimant = 0;
int LEDaimant = 13;
int LEDallumage = 3;
int Bouton = 7;

void setup() {
    // initialisation des entrées sorties
    pinMode(Electroaimant, OUTPUT);
    pinMode(LEDaimant, OUTPUT);
    pinMode(LEDallumage, OUTPUT);
    pinMode(Bouton,INPUT_PULLUP);
    //Allumer la LED d'allumage à l'initialisation
    digitalWrite(LEDallumage, HIGH);
}

void loop() {
  
  //lecture de l'état du bouton et stockage dans etatBouton
  boolean etatBouton = digitalRead(Bouton);
  //test des conditions
  if (etatBouton==LOW)//test si bouton appuyé (utiliser un bouton en pull up inverse l'état logique reçu)
  {
    digitalWrite(Electroaimant,HIGH); //Electroaimant allumé
    digitalWrite(LEDaimant,HIGH); //LEDaimant allumée
  }
  if (etatBouton==HIGH)//test si bouton levé
  {
    digitalWrite(Electroaimant,LOW); //Electroaimant éteint
    digitalWrite(LEDaimant,LOW); //LEDaimant éteinte
  }
  delay(100); //petite attente
}
