# Caro V 0.1

La robot curieuse.

## Description générale

Caro, la robot-caméra, filme les événements du labo et projette les images sur l'écran A du labo. Elle est autonome et se déplace dans le labo pour composer ses images.

<small>(Prénom en ref à [Caroline Champetier](https://fr.wikipedia.org/wiki/Caroline_Champetier))</small>

## Allure

Fixé sur une structure mobile à 4 roues, un mat prolongé d'un col de cygne est équipé d'une caméra.

## Description technique

La strucure mobile est un hacking de Crawler télécommandé. La télécommande est gérée par le régisseur.

![robot_camera_V_01](/ressources/photos/robot_camera_V_01.jpg)

### Mécanique

- crawler modifié
- Mat téléscopique type pied de micro en alu
- col de cygne

![crawler_kino](/ressources/divers/crawler_kino.jpg)

### La vidéo

Deux systèmes actuellements developpés :
- Liaison HF
- Liaison IP

#### Liaison HF

La caméra fixée au col de cygne délivre un signal à un émetteur HF qui transmet l'image jusqu'au vidéoprojecteur situé derrière l'écran de l'établi.

##### Materiel

Sur Caro :
- Mini caméra (rugissant)
- Émetteur HF

Reception :
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

Pour l'instant on selectionne le **2**


#### Liaison IP

##### Materiel

Sur Caro :
- Caméra Mi Hom Security Camera 360 (MJSXJ02CM)

La caméra est équipée d'une platine ammovible avec deux trous de 3mm de diamètre espacés de 36mm (centre à centre)

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
