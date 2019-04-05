# Jimi

## Description générale

Jimi est une intelligence machine qui joue de la guitare, il peut improviser ou bien jouer selon un rythme qui lui est fourni en entrée.

## Allure

![](/ressources/photos/jimi.JPG)

## Matériaux

Planche de bois comportant une corde de guitare, un micro de guitare, des mécaniques et un moteur pas à pas sur lequel est fixé un petit bras métalique qui enserre un médiator en plastique (plastique de couvercle de pot de cafés).

![](/ressources/photos/jimi_moteur.JPG)

Une fenêtre rectanglaire est découpée dans le bois et est cachée par une plaque métallique à l'arrière de laquelle est fixée toute l'électronique.

En façade de la plaque on retrouve la sortie audio de Jimi en gros jack, une entrée petit jack pour la réception d'un signal de gate, une LED qui s'allume lorsque le moteur est actif, un potentiomètre de volume et un autre permettant d'ajuster la position du bras-médiator par rapport à la corde. A l'arrière est fixé l'arduino.

Deux jambes amovibles munies de pieds viennent se fixer derrière la planche, cela lui donne l'air super cool.


## Hypothèses de construction, description technique

Le bouton poussoir est maintenu à l'état haut par une résistance de pull-up interne à l'arduino. Pour maintenir un état bas sur l'entrée gate, une résistance 10k est soudée en pull down.
Le code est entièrement séquentiel, les actions ne se déroulent jamais simultanément. Ainsi lorsque le moteur bouge, c'est la seule action que l'arduino puisse réaliser. Ainsi il ne peut par exemple pas détecter de gate ou d'information du bouton poussoir.

Quand on appui sur le bouton, un générateur de nombres aléatoires tire au hasard un nombre entre 0 et 2. Si c'est 0 rien ne se passe, si c'est 1 Jimi joue une note et si c'est 2 il joue deux notes rapprochées.
Le code de l'arduino est disponible [ici](../../sources/arduino/jimi).

![](/ressources/photos/jimi_dos.JPG)



## Améliorations envisagées

- Déporter l'alimentation en façade
- Améliorer le rangement 
- Améliorer le système de maintien des médiators pour pouvoir en changer facilement.
- Finir le support permettant d'acceuillir une batterie
- Scier vis à l'arrière

## Moment envisagé pour la construction et/ou les améliorations

[Retour à la liste des robots du laboratoire](.)
