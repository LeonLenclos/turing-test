
# Echo

## Descritpion générale
Quant on lui présente un objet, il dit ce qu'il en pense. C'est un robot qui a du goût, un goût qui lui est propre.

## Allure
Petit buste fait d'un assemblage de pièces de PVC, peint à la bombe pour un effet métallisé.
Un manomètre et un bouton sont en façade sur son buste, à la place des yeux il possède un capteur de distance à ultrasons.


## Matériaux envisagés
Assemblage de raccords en PVC avec l'électronique fixée dedans.


## Hypothèses de construction, description technique
Arduino branché à une enceinte et à un capteur ultrason qui permet de détecter la présence d'objets et de calculer leur distance. La lecture d'un échantillon 'commentaire élogieux' est déclenchée quant un objet entre dans une gamme de distances par rapport au robot (entre 10cm et 50cm). Il faut alors que l'objet sorte du champ visuel du robot pour que l'introduction d'un autre objet déclenche un autre commentaire. Le code de l'arduino est disponible [ici](../../sources/arduino/echo)

## Améliorations

- Construire une platine, un support pour Echo.
- Installer une LED qui informe si echo pense qu'il est en présence d'un objet ou pas
- Revoir la fixation de l'arduino
- Déporter les ports de l'alimentation et de la sortie enceintes à l'arrière d'Echo
- Ajouter une entrée jack pour pouvoir recevoir du trig ou du gate et pouvoir lire des samples audio en rythme ("youpi !" ou encore "C'est super !")


## Moment envisagé pour la construction

Usinotopie printemps 2018
