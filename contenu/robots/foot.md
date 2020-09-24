# Foot
![Foot](/ressources/photos/foot.JPG)
## Description générale

Foot, le Robot qui souffre. Quand il subit un choc, il gémit proportionnellement à l'intensité du choc.

Il a été évoqué [ici](../scenes/anthropomorphisme.md).

## Allure

Une boite en carton. Simple.
C'est tout...
Une simple boite en carton.

## Matériaux

- Profilés alu pour la structure
- Un carton
- Un module arduino
- Un micro contact piezo électrique
- Un [shield audio](https://www.adafruit.com/product/1788) avec un lecteur de carte SD.
- Un [module d'amplification de puissance](https://www.audiophonics.fr/fr/modules-amplificateur/wondom-aa-ab32178-module-amplificateur-tpa3116-class-d-2-x-50-watts-4-ohms-p-10052.html)
- Deux enceintes haut rendement Celestion [TF1510](https://www.terredeson.com/tf01510.html)
- Une batterie LI-ion pour l'alimentation

## Hypothèses de construction, description technique

Comme le carton doit recevoir des chocs, il faut éviter qu'il se désagrège et que l'électronique embarquée se détériore. Nous avons donc choisi une structure alu légère.

![Foot](/ressources/photos/FOOT_1_SMALL.jpg)

Trois capteurs piezo sont fixés sur la structure (sur les vis à la base des cordelettes, chaque cordelette a le même nombre de traits que le numéro du piezo placé à côté).

![Foot](/ressources/photos/FOOT_3_SMALL.jpg)

Au milieu de la structure est suspendue une section de tube PVC qui accueille :

- l'arduino, 
- l'ampli de puissance
- les deux enceintes cablées en opposition de phase pour un meilleur rendement.
- La batterie

![Foot](/ressources/photos/FOOT_4_SMALL.jpg)

Le code arduino de foot est disponible [ici](../../sources/arduino/foot).

![Foot](/ressources/photos/FOOT_2_SMALL.jpg)


Foot est doté d'une entrée mini-jack permettrait de déclencher la lecture de samples lors de la réception d'un signal trig ou gate émis depuis [Core](/contenu/robots/core.md).

## Moment envisagé pour la construction

Foot a été conçu à l'Usinotopie mars 2018 et amélioré dans les résidences qui ont suivies.

![](/ressources/photos/foot_fabi.JPG)

## Améliorations

- La souffrance du robot pourrait être aussi induite par des soubresauts ou des tremblements qui pourraient être obtenus avec un moteur entrainant un disque dont le centre de gravité est décentré.

- Régler le problème de la sensibilité. Dans l'état actuel, un seul piezzo est opérationnel...

[Retour à la liste des robots du laboratoire](.)
