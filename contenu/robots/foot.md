# Foot
![](/ressources/photos/foot.JPG)
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
- Un shield audio avec des sorties amplifiées pour les enceintes 
- Un micro contact piezo électrique
- Deux enceintes
- Une batterie usb pour l'alimentation

## Hypothèses de construction, description technique

Comme le carton doit recevoir des chocs, il faut éviter qu'il se désagrège et que l'électronique embarquée se détériore. Nous avons donc choisi une structure alu légère. Trois capteurs piezo sont fixés sur la structure (sur les vis à la base des cordelettes, chaque cordelette a le même nombre de traits que le numéro du piezo placé à côté). Au milieu de la structure est suspendue une section de tube PVC qui accueille l'arduino et les deux enceintes cablées en opposition de phase pour un meilleur rendement.
La sortie jack du shield donne la possibilité de brancher foot sur des enceintes autres que celles qui y sont intégrées.
Le code arduino de foot est disponible [ici](../../sources/arduino/foot).

## Moment envisagé pour la construction

Usinotopie mars 2018

![](/ressources/photos/foot_fabi.JPG)

## Améliorations

- Doter Foot d'une entrée jack permettrait de déclencher la lecture de samples lors de la réception d'un signal trig ou gate qui pourrait être émis depuis un synthétiseur.

- La souffrance du robot pourrait être aussi induite par des soubresauts ou des tremblements qui pourraient être obtenus avec un moteur entrainant un disque dont le centre de gravité est décentré.

- Régler le problème de la sensibilité peut-être en ajouttant d'autres piezos

[Retour à la liste des robots du laboratoire](.)
