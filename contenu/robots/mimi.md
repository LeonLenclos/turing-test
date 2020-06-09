# Mimi

## Description générale

Mimi est un robot qui se déplace de manière plus ou moins controlée. Lorsque les chercheurs du GRIM quittent le laboratoire, elle a des tendances suicidaires qui la poussent à se jeter du haut de son étagère

![Mimi](/ressources/photos/MIMI_1_SMALL.jpg)

## Allure

Une hélice de drone fixée sur un carton. Le carton contient un Arduino qui envoie des messages à un ESC (Electronic Speed Control) qui contrôle la vitesse du moteur de l'hélice. L'arduino est équipé d'un récepteur infrarouge permettant le côntrole du moteur via une télécommande. 

## Protocoles d'allumage et d'extinction

- Brancher la fiche de l'ESC au shield (cable brun à droite et le jaune à gauche lorsqu'on regarde le récepteur infrarouge de face)
- Mettre l'arduino sous tension
- Appuyer sur le bouton Standby de la télécommande. A partir de ce moment vous avez 6 secondes pour effectuer l'étape suivante
- Brancher la batterie à l'ESC
- Have fun

## Risques

Si l'arduino se débranche, le moteur peut rester sur la dernière vitesse qu'il a reçu. Dans ce cas, il faut soit débrancher la batterie des moteurs, soit rebrancher l'arduino.

## Description technique

### Software

Code arduino disponible [ici](https://github.com/LeonLenclos/turing-test/blob/master/sources/arduino/mimi/mimi.ino).

### Shield

- Shield fait maison comportant un récepteur infrarouge et une fiche pour brancher l'ESC.
- Si on regarde le récepteur infrarouge de face (croix métallique X visible), l'avant du Shield est placé sur l'arduino sur les PinsDigital 9 jusqu'à GND. 
- A l'arrière le shield est placé sur la Pin 5V et va jusqu'à la fin de la barette Power, une branche du connecteur dépasse de la barette.

Le connecteur de l'ESC doit être branché avec le cable brun à droite et le jaune à gauche lorsqu'on regarde le récepteur infrarouge de face.

### Telecommande

- Quand le moteur est allumé, une clock est initialisée, au bout de 3 secondes, si elle n'est pas réinitialisée, elle éteint le moteur.
- Bouton Stanby : Lance l'initialisation de l'ESC
- Bouton 9 : Programme pour la scène de réglage de l'hélice de Fabien. Il lance le moteur à fond et initialise la clock.
- Bouton play : Réinitialise la clock et allume le moteur s'il était éteint
- Bouton stop : Coupe le moteur
- Bouton 0 : Coupe le moteur
- Boutons >> et << : augmentent et diminuent la vitesse, réinitialisent la clock.
- Bouton 1 : Lancer la fonction suicide (allume le moteur à fond pendant un temps court).

## Améliorations envisagées

Bouton suicide à placer sur le Shield. Ce bouton doit déclencher après un délai de temporisation la fonction suicide.
