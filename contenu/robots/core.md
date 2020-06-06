# Core V 1

## Description générale

Core est un robot chef d'orchestre. Il donne le tempo et la partition à toutes les autres créatures artificielles du Labo.

![CORE V1](/ressources/photos/CORE_V1.jpg)

Core, le cerveau du GRIM.

## Description technique

Core est un petit rack format eurorack équipé de :
- Une clock
- Un sequenceur de trig
- Un utilitaire de trig (retard et allongement)
- Un serveur OSC
- Un switch ethernet

Ses fonctions principales sont :

- Composer un rythme qui peut être distribué aux machines du GRIM en Trig (minijack) ou en OSC (RJ45)
- Connecter toutes les machines équipées d'une interface réseau sur un même réseau.

### Intégration au réseau

Voilà le schéma du réseau :

![grim-network](/ressources/divers/grim-network.png)

- Foot, Jimi et Echo sont des robots en arduino avec un entrée gate
- Lucy et Alan des robots qui fonctionnent en raspberry ou PC.
- SEQ = séquenceur de trig [doepfer A 157-1/2/3](http://www.doepfer.de/a157.htm)
- CLK = générateur d'horloge [Clock O'Pawn Shakmat Modular](http://www.shakmatmodular.com/products/cop.html)
- OSC SERVEUR = Raspberry Pi équipé d'une interface d'entrée 4 trigs
- SWITCH = Gigabit RJ45 Netgear ProSAFE GS108GE 8 ports
- Mod = Synthé modulaire
- PD = pure date sur un Raspberry pour synthèse sonore
- OGN/OGN VIEW = Sur un PC + un Raspberry, [OGNON](https://github.com/LeonLenclos/Ognon), logiciel de création d'animation en temps réel.

### Patch et cablage des modules

#### Entrées

En spectacle Core reçoit l'horloge directement de la sortie Trig 3 de la TR 808 et le reset de la TT 303. (Le générateur d'horloge n'est utilisé qu'en stand alone pour test ou dépannage.)

- TR 808 out trig 3 ---> in seq click in
- TT 303 reset out ---> in seq reset

#### Patch OSC

Le server OSC (raspberry) dispose de 4 entrées trig (mini-jack) ainsi que d'une sortie ethernet (RJ45). Son rôle est de dispatcher les trigs à différentes adresses IP sous forme de messages OSC via les deux switch.

- seq out trig 2 ---> in RPI 4 ---> Alan talk_alone
- seq out trig 3 ---> in RPI 3 ---> Alan lalala
- seq out trig 6 ---> in RPI 2 ---> Lucy
- seq out trig 8 ---> in RPI 1 ---> Pure Data
- Les deux switchs sont connectés entre eux
- Le serveur OSC est connecté à un des deux switchs
- Les machines du GRIM sont connectées indifféremment à l'un des deux switchs.

#### Patch de l'interface trig/RPI

Le GRIM a conçu une interface pour ajouter des entrées trig 10v au raspberry. Pour plus d'informations concernant le circuit électronique, consulter le chapitre *interface Raspberry/Arduino/trig* dans cette [note technique](/contenu/organisation/notes-techniques.md).

    VCC     : PIN1      (3.3V)
    GND     : PIN9      (GND)
    RPI 1  : PIN7      GPIO04
    RPI 2  : PIN11     GPIO17
    RPI 3  : PIN13     GPIO27
    RPI 4  : PIN15     GPIO22
    GND     : PIN 39    (GND)

#### Patch analogique

- seq out trig 1 ---> A162 doepfer (trig to gate) ---> Jimi (gate)
- seq out trig 4 ---> Écho (trig)
- seq out trig 5 ---> A162 doepfer (trig to gate) ---> Foot (gate)
- seq out trig 7 ---> Synthé modulaire (trig)

### Intégration

Petit fly rack 3U avec une pochette intégrée dans laquelle :
    - cables RJ45
    - 2 alim netgear
    - 1 alim rbpi
    - 1 alim modulaire
    - La doc

## Software

Le serveur écoute les trigs sur ses entrées et envoie les messages correspondants sur sa table de dispatch. Voir le [code](/sources/python/core.py)

### Table de dispatch

indique quel message envoyer à quelle adresse ip en fonction des trigs qu'il reçoit

Par exemple : [dispatch_table.py](/sources/python/dispatch_table.py)

### Comment mettre à jour la table de dispatch

Pour se connecter en ssh à core

`ssh pi@core.local` ou `ssh pi@10.0.0.11`

mot de passe : SIMPLE_GRIM_MDP

Puis il faut modifier `~/dispatch_table.py`

Puis il faut `sudo reboot`

### Notes techniques

Le programme est lancé au demarrage du raspberry avec une commande dans `/etc/rc.local`

## Améliorations envisagées

- Centraliser les alims
- Voyant quand le serveur OSC est en route (boffement utile)
- 2 sorties trig pour le serveur OSC
- Le serveur écoute les messages OSC de type `/trig/ n` et envoie un trig sur la sortie `n`.
- Bug : Core ne peut pas recevoir deux trigs à la fois
- Bug : Core lag et saute donc des pas quand il cherche à envoyer de l'osc à un ordi éteint.

## Moment envisagé pour la construction et/ou les améliorations.

Du 15/3/2019 au 31/3/2019 à Graulhet puis résidence 104 du 15 au 21 avril 2019

## note concernant l'utilisation du PATHS by RYO (abandonné)

A une certaine phase de développement du robot, nous avons été amené à télécommander le patch des sorties trig du séquenceur avec un module PATHS de chez RYO.
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

[Retour à la liste des robots du laboratoire](.)



