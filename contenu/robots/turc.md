# Turc V 1.0

## Description générale

Turc est un robot qui sait jouer au morpion, mais qui n'aime pas perdre.

![Turc-Vue d'ensemble](/ressources/photos/turc5.JPG)

## Allure

C'est un quadripède avec un bras articulé au bout duquel est fixé un électroaimant qui lui permet de se saisir de pièces métaliques.

## Matériaux 

- Parties fixes et mobiles en Aluminium. Rondelle en Téflon PTFE et Visserie BTR M10 avec écrous Stop
- Verrins pneumatiques
- articulations sur paliers et rotules

### Note sur l'entretient des verrains.

Il convient de décrasser régulièrement les verrains à l'alcool à 90° puis de regraisser très légèrement par exemple avec de la graisse de nez.

![think-exclamation](/ressources/icons/think-exclamation.png) Attention : pensez à vous lavez les mains entre l'utilisation de l'alcool à 90 et la collecte de votre graisse de nez.

![Turc-Détail des articulations](/ressources/photos/turc4.JPG)

## Description technique

Une télécommande équipée de trois verrins et d'un interrupteur permet de controler la position du bras et la préhension de la pièce métalique à saisir.

![Turc-La télécommande](/ressources/photos/turc3.JPG)

6 tuyaux transmettent la pression au 3 autres verrins qui commandent le bras du robot sur 3 axes : tilt, pan et allongement .

Turc est optimisé pour jouer sur un plateau de ~150mm par ~150mm à une hauteur de ~250mm.

### Mécanique

Basée sur les transmissions pneumatiques

### Electronique

- Arduino UNO
- electroaimant

### Software

- [Code Arduino de turc](../../sources/arduino/turc/turc.ino)

## Améliorations envisagées

- Boules télécommande (vis 8mm)
- Harnais télécommande

![Turc-La télécommande](/ressources/photos/turc2.JPG)

[Retour à la liste des robots du laboratoire](.)
