# Core V 0.1

## Description générale

Core est un robot chef d'orchestre. Il donne le tempo à toutes les autres créatures artificielles du Labo.

![CORE V0](/ressources/divers/CORE_V0.1.jpg)

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

Le server OSC (raspberry) dispose de 4 entrées trig (mini-jack) ainsi que d'une sortie ethernet (RJ45). Son rôle est de dispatcher les trig à differentes adresses IP sous forme de messages OSC.

#### Patch RJ45

- Les deux switchs sont connectés entre eux
- Le serveur OSC est connecté à un des deux switchs
- Les machines du GRIM sont connectés indiferament à l'un des deux switch

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
- Lucy et Alan des robots qui fonctionne en raspberry ou PC.
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
- 2 sortie trig pour le serveur OSC
- Le serveur écoute les message OSC de type `/trig/ n` et envoie un trig sur la sortie `n`.
- Problème : il semble que core se met en veille (???)
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