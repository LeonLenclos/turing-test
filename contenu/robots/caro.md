# Caro V2

![CARO_V1_3_SMALL](/ressources/photos/CARO_V1_3_SMALL.jpg)

La robot curieuse.

## Description générale

Caro, la robot-caméra, filme les événements du labo et projette les images sur l'écran A du labo. Elle est autonome et se déplace dans le labo pour composer ses images.

<small>(Prénom en ref à [Caroline Champetier](https://fr.wikipedia.org/wiki/Caroline_Champetier))</small>

## Allure

Fixé sur une structure mobile à 4 roues, un mat prolongé d'un col de cygne est équipé d'une caméra.

## Description technique

La strucure mobile est un hacking de Crawler télécommandé. La télécommande est gérée par le régisseur.

### Mécanique

- crawler modifié
- Mat téléscopique type pied de micro en alu
- col de cygne

![CARO_V2_SMALL](/ressources/photos/CARO_V2_SMALL.jpg)

#### La vidéo

- caméra Blackmagic Micro Cinéma 2K
- objectif Samyang 7,5mm

![CARO_V1_1_SMALL](/ressources/photos/CARO_V1_1_SMALL.jpg)

#### Liaison HF

- Émetteur/recepteur vidéo HD Teradek ACE 500

![ACE TERRADEK 500](/ressources/photos/ACE TERRADEK 500.jpg)

## Anciennes version

Plusieurs versions de caméra et d'émetteur/récepteur HF ont été testés avant d'aboutir à la version 1.

### V1.1 - Caméra analogique et émeteur/récepteur 1,2 GHz

![robot_camera_V_01](/ressources/photos/robot_camera_V_01.jpg)

Cette version a été abandonnée à cause du manque de qualité des images et du manque de fiabilité de la liaison HF.

#### La vidéo

Sur Caro :
- caméra sd + série d'objectifs miniatures
- Émetteur HF

#### Liaison HF

Emission/Reception :
- 1,2 G TX 1000 mW 1000mW 8CH Transmitter RX02

![emetteur_kino](/ressources/divers/emetteur_kino.jpg)

##### Note relative aux objectifs utilisables sur la mini caméra

4 Objectifs :
On les range dans l'ordre de la plus courte à la plus longue focale.
On peut regarder la taille de l'iris : Plus petit trou = Plus courte focale

1.  très grand angle = .
2.  grand angle = °
3.  longue focale = o
4.  très longue focale = O

Autres signes distinctifs :

1.  Le pas de vis ne va pas jusqu'au bout
2.  Le plus grand pas de vis
3.  Inscriptions sur l'objectif
4.  Le dernier

on selectionne le **2**

### V1.2 - Caméra analogique et liaison IP

Cette version a été abandonnée à cause du délai de transmission des images via IP.


#### La vidéo

Sur Caro :
- Caméra Mi Hom Security Camera 360 (MJSXJ02CM)

La caméra est équipée d'une platine ammovible avec deux trous de 3mm de diamètre espacés de 36mm (centre à centre)

#### Liaison HF

Reception :
- Routeur wifi
- ordinateur.

##### Fonctionnement

Grâce à un delicieux hack de [telmomarques](https://github.com/telmomarques) on peut récuperer le flux vidéo de la caméra.

- suivre https://github.com/telmomarques/xiaomi-360-1080p-hacks
- suivre https://github.com/telmomarques/xiaomi-360-1080p-video-stream
- et enfin https://github.com/telmomarques/xiaomi-360-1080p-hacks/issues/2#issuecomment-490490622

Sur l'ordi qui diffuse la commande est : `ffplay udp://<your_computer_ip>:12345`



----

[Retour à la liste des robots du laboratoire](.)
