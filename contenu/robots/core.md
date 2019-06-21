# Core V 0.1

## Description générale

Core est un robot chef d'orchestre. Il donne le tempo à toutes les autres créatures artificielles du Labo.

![CORE V1](/ressources/divers/CORE V1.jpg)

Le cerveau de Core


## Description technique

Core est un petit rack format eurorack équipé de :
- Une clock
- Un sequenceur de trig
- Un serveur OSC
- Un switch ethernet

Ses fonctions principales sont :
- Composer un rythme qui peut être distribué aux machines du GRIM en Trig (minijack) ou en OSC (RJ45)
- Connecter toutes les machines équipées d'une interface réseau sur un même réseau.

### Patch

#### Trig <-> OSC

Le server OSC (raspberry) dispose de 4 entrées trig (mini-jack) ainsi que d'une sortie ethernet (RJ45). Son rôle est de dispatcher les trigs à différentes adresses IP sous forme de messages OSC.

#### Patch RJ45

- Les deux switchs sont connectés entre eux
- Le serveur OSC est connecté à un des deux switchs
- Les machines du GRIM sont connectées indifféremment à l'un des deux switchs

#### Patch provisoire

Sorties trig-seq :
- 1 Trig ber
- 2 Alan lalaléla (rpi 3)
- 3 SQ1
- 4 Lucy (rpi 2)
- 5 Jimi
- 6 Acte 2 (rpi 1)
- 7 Alan talk_alone (rpi 4)
- 8 Beatbox

### Réseau

Core est une machine pour synchroniser et mettre en reseau toutes les machines du Grim.

Voilà le schéma du réseau :

![grim-network](/ressources/divers/grim-network.png)

(source : [grim-network.dia](/sources/dia/grim-network.dia))

- Foot, Jimi et Echo sont des robots en arduino avec un entrée gate
- Lucy et Alan des robots qui fonctionnent en raspberry ou PC.
- SEQ = [doepfer A 157-1/2/3](http://www.doepfer.de/a157.htm)
- CLK = [Clock O'Pawn Shakmat Modular](http://www.shakmatmodular.com/products/cop.html)
- OSC SERVEUR = Raspberry Pi
- Mod = Synthé modulaire
- PD = pure date sur un Raspberry pour synthèse sonore
- OGN/OGN VIEW = Sur un PC + un Raspberry, [OGNON](https://github.com/LeonLenclos/Ognon), logiciel de création d'animation en temps réel.


### Electronique

- Un commutateur 8 ports (e.g. *Switch réseau Gigabit RJ45 Netgear ProSAFE GS108GE 8 ports*)
- Un générateur d'horloge 
- Un sequenceur trig
- Un raspberry qui dispatche du OSC sur du Trig et vice versa
- Un module Switch pour les trig (switch by RYO), situé au dos de Core

#### Module Switch by RYO

Ce module permet de basculer l'envoi de trig au raspberry.
En position 1 (LED allumée en haut) le trig Pure data venant de Core est envoyée vers le raspberry, le trig d'Alan est envoyé vers une sortie vide.
En position 2 (LED allumée un cran plus bas) le trig Pure data est envoyé vers une sortie vide venant de Core, le trig d'Alan est envoyée vers le raspberry.
Pour passer de la position 1 à 2 et inversement, il suffit d'appuyer sur le bouton FWD. A l'avenir, il suffira d'envoyer un trig dans l'entrée FWD du switch.

Les connexions du switch sont les suivantes

Le bouton steps est sur la position 2

Switching
 - 1   2   PD/PD
 - 0   0
 - 3   0   AL/
 - 0   4   /AL
 
 Avec : 
 - 1 Pure Data in
 - 2 Pure Data out
 - 3 Alan in
 - 4 Alan out

#### Patch du module maison

    VCC     : PIN1      (3.3V)
    GND     : PIN9      (GND)
    TRIG 1  : PIN7      GPIO04
    TRIG 2  : PIN11     GPIO17
    TRIG 3  : PIN13     GPIO27
    TRIG 4  : PIN15     GPIO22
    GND     : PIN 39    (GND)

### Software

Le serveur écoute les trigs sur ses entrées et envoie les messages correspondants sur sa table de dispatch. Voir le [code](/sources/python/core.py)


#### Table de dispatch

indique quel message envoyer à quelle adresse ip en fonction des trigs qu'il reçoit

Par exemple : [dispatch_table.py](/sources/python/dispatch_table.py)


#### Comment mettre à jour la table de dispatch

Pour se connecter en ssh à core

`ssh pi@core.local` ou `ssh pi@10.0.0.11`

mot de passe : SIMPLE_GRIM_MDP

Puis il faut modifier `~/dispatch_table.py`

Puis il faut `sudo reboot`

#### Notes techniques

Le programme est lancé au demarrage du raspberry avec une commande dans `/etc/rc.local`

## Améliorations envisagées

- Centraliser les alims
- Voyant quand le serveur OSC est en route (boffement utile)
- 2 sorties trig pour le serveur OSC
- Le serveur écoute les messages OSC de type `/trig/ n` et envoie un trig sur la sortie `n`.
- Bug?? : il semble que core se met en veille (??? à confirmer, pas l'impression d'avoir vu ça depuis la v0)
- Bug : Core ne peut pas recevoir deux trigs à la fois
- Bug : Core lag et saute donc des pas quand il cherche à envoyer de l'osc à un ordi éteint.
- Rajouter un bouton trig vers l'entrée FWD du module Switch by RYO

## Moment envisagé pour la construction et/ou les améliorations.

Du 15/3/2019 au 31/3/2019 à Graulhet puis résidence 104 du 15 au 21 avril 2019

[Retour à la liste des robots du laboratoire](.)

## Logistique

Petit fly rack avec une pochette intégrée dans laquelle :
    - cables RJ45
    - 2 alim netgear
    - 1 alim rbpi
    - 1 alim modulaire
    - La doc
