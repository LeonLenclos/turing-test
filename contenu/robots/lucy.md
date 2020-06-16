# Lucy

![](/ressources/lucy.JPG)

## Description générale

Lucy est une référence aux [tamagotchis](https://fr.wikipedia.org/wiki/Tamagotchi). C'est un personnage virtuel, il meurt si on le nourrit trop ou pas assez.

## Esthétique, allure du robot

Un simple écran avec un bouton au-dessus : nourrir. Un personnage très pixellisé s'affiche à l'écran, en temps normal il bouge légèrement dans son écran. Quand il est nourri, une animation est lancée. Il peut avoir l'air maigre, normal ou gros.

![](/ressources/photos/lucy1.JPG)![](/ressources/photos/lucy2.JPG)![](/ressources/photos/lucy3.JPG)![](/ressources/photos/lucy4.JPG)

## Matériaux

Carton, worbla, écran, divers electronique.

## Mise en scène

Ce robot fait partie de la vie du labo, quelqu'un peut proposer de le mettre à jour mais cela pose des problèmes moraux aux autres qui se sont attachés à leur petit poisson pixellisé. En même temps ils s'en veulent aussi de maintenir en vie un poisson enfermé pour leur seul plaisir, ils résolvent le problème en adaptant le robot musicien pour qu'il nourisse le robot au lieu d'appuyer sur des touches de piano, ils se dédouanent ainsi de leurs responsabilités.

## Description technique

Lucy tourne sur un Raspberry 3B+ avec un [écran 10.1" 1024x600 HDMI LCD](https://www.kubii.fr/ecrans-afficheurs/2237-ecran-tactile-101-1024x600-hdmi-lcd-kubii-3272496011458.html). 

Pour les infos sur le fonctionnment du programme consultez [le dépõt git de Lucy](https://github.com/LeonLenclos/lucy)

Le programme est lancé au demarrage du raspberry grâce à crontab (voir : `sudo crontab -e`)

## Améliorations

- Mettre à jour la version de Lucy (depuis [son dépõt git](https://github.com/LeonLenclos/lucy))

### Facultatif

- Déporter le RJ45 en façade.
- Mettre un schuko en façade pour l'alimentation.

[Retour à la liste des robots du laboratoire](.)
