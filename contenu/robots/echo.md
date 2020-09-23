
# Echo

![](/ressources/photos/echo.JPG)

## Descritpion générale
Quand on lui présente un objet, il dit ce qu'il en pense. C'est un robot qui a du goût, un goût qui lui est propre.

## Allure
Petit buste fait d'un assemblage de pièces de PVC, peint à la bombe pour un effet métallisé.
Un manomètre, un potentiomètre et une led sont en façade sur son buste, à la place des yeux il possède un capteur de distance à ultrasons. Dans sa dernière version, le buste est fixé à une enceinte préamplifiée qui lui donne une voix claire et puissante.

![](/ressources/photos/ECHO_V1_1_SMALL.jpg)

## Matériaux
Assemblage de raccords en PVC avec l'électronique fixée dedans.

## Construction, description technique
Arduino branché à une enceinte amplifiée et à un capteur ultrason qui permet de détecter la présence d'objets et de calculer leur distance. La lecture d'un échantillon 'commentaire élogieux' ou 'commentaire dépréciatif' est déclenchée aléatoirement quand un objet entre dans une gamme de distances par rapport au robot (entre 10cm et 50cm). Il faut alors que l'objet sorte du champ visuel du robot pour que l'introduction d'un autre objet déclenche un autre commentaire.  

Le code de l'arduino est disponible [ici](../../sources/arduino/echo/echov2/echov2.ino)

## Améliorations effectuées
- Une LED informe si echo pense qu'il est en présence d'un objet ou pas.
- Un Vumètre indique la distance entre l'objet et le capteur.
- Un potentiomètre relié à l'arduino influence le choix entre des commentaires élogieux et d'autres dépréciatifs.
- Une entrée mini-jack permet de recevoir du trig ou du gate pour pouvoir lire des samples audio en rythme ("youpi !" ou encore "C'est super !")

## Historique
Echo a été conçu à l'Usinotopie au printemps 2018 et amélioré dans les résidences qui ont suivi.

[Retour à la liste des robots du laboratoire](.)
