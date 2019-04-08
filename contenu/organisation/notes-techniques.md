Notes Techniques
================

## Les cables <3

indentification des cables : `(longueur, couleur du cable, (+couleur du repère))`

### Longs cables (Standard Grim)

Les longs cables passent si possible par le haut.

- Audio = XLR (+ DI + raccord minijack/jack)
    - Console Sonosax  <--> MS20 (12m, jaune (+bleu))
    - Console Sonosax  <--> Godel R (12m, jaune (+rouge))
    - Console Sonosax  <--> Godel L (12m, jaune (+vert))
    - Console Sonosax  <--> micro fab (12m, rouge (+jaune))
    - Console Sonosax  <--> micro leon (10m, rouge (+vert))
    - Console Sonosax  <--> reverb metro (15m, rouge (+noir))
    - Console Sonosax  <--> boite à rythme (15m, jaune (+noir))
- Ethernet = RJ45
    - Core <--> Alan (25m, blanc)
    - Core <--> Lucy (15m, vert)
    - Core <--> Godel (15m, vert)
    - Core <--> Ottomann (15m, vert)
    - Core <--> Ail (10m, bleu)
- Trig/Gate/CV = MiniJack
    - Core <--> Moduber
    - godel <--> Moduber (4m)
    - Core <--> SQ1 (15m, jaune)
    - Core <--> Echo (3m, vert)
    - Core <--> Jimi (14m, rouge)
    - Core <--> Foot (14m, bleu)
    - Core <--> Dedo 

### Cables courts (Standard Grim)


- Audio = XLR (+ DI + raccord minijack/jack)
    - Console Sonosax <--> Moduber stero 1 et 2 (2m50, rouge)
    - Console Sonosax  <--> micro ber (5m, rouge (+bleu))
- Ethernet = RJ45
    - Core <--> Core (15cm, rouge) x2
- Trig/Gate/CV = MiniJack
    - Core <--> Core

### Alims

Plusieurs options possibles pour l'alimentation des robots :

####  Alimentation secteur. 
    - Idéal si les robots restent en place (Lucy, Alan, Core, etc)
    
####  LIPO 
     - Déliat, fragile, dangeureux mais puissant
     - Connecteurs CSIX2 (+ = carré / - = rond / femelle = vers batterie)
         
####  LI-ion
     - peut=être moins critique que LIPO en termes de de fragilité
     - format standard.

### Piles rechargeables
     - faible rendement
    
####  5V = USB Power Bank. 
    - Bon rapport energie/prix 
    - Deux gros défauts : Limité à 5V et s'etteind innopinément (voir ci-dessous)

Ça a marché avec certains arduino mais ça ne semble pas très fiable. Problème : ça s'eteind
tout seul quand cela détecte une trop faible consomation.

> power banks also have some minimal discharge current, and shut off if the discharge current is below this threshold. They treated my Arduino as "leakage" and shut off

2 solutions selon [ce thread](https://forum.arduino.cc/index.php?topic=305175.0) 

1- Hackage : faire consommer à la batterie ce qu'il faut pour pas qu'elle ne s'etteigne ([exemple](https://hackaday.com/2013/11/08/tricking-a-usb-power-supply/))
2- Achat : trouver des batteries avec un mode 'always on' ([exemple](https://www.amazon.com/gp/product/B00ME3ZH7C/ref=oh_aui_detailpage_o09_s00?ie=UTF8&psc=1))


## arduino, cv et gate.

L'interface gate ressemble à ça :

![interface-gate](/ressources/divers/interface-gate.png)


### References circuits

Le Git d'un shield pour interfacer modulaires et arduino : Synapse de chez Shaduzlabs

[lien vers le Github](https://github.com/shaduzlabs/synapse)

[lien vers le Blog](http://www.shaduzlabs.com/blog/21/synapse-a-diyfriendly-cv-io-shield-for-arduino.html)

![shéma synapse 1](/ressources/divers/synapse_4.png)

![shéma synapse 2](/ressources/divers/synapse_5.png)

## arduino et servomoteur.

![shéma arduino/servo](/ressources/divers/cablage_servo_arduino.png)

## mesures minimales Scene

Mesures prises à Bessines :
- Profondeur minimale : 6m
- Ouverture minimale : 7,75m
- Hauteur minimale : 3m 

## Réseau

Les machines connectées au réseau :
- Thinkpad de Léon pour Ognon : ottomann.local (10.0.0.2)
- Raspberrypi pour Ognon : ail.local (10.0.0.15)
- Raspberrypi de Fab pour Puredata : godel.local (10.0.0.3)
- Core : core.local (10.0.0.11)
- Lucy : lucy.local (10.0.0.13)
- Alan : alan.local (10.0.0.10)

## Ail

Le rpi qui diffuse ognon :
- est mis en vertical grace à une ligne dans `/boot/config.txt` (https://www.raspberrypi.org/forums/viewtopic.php?t=120793)
- lance chrome au demarrage grace au contenu de `/home/pi/.config/lxsession/LXDE-pi/autostart` https://raspberrypi.stackexchange.com/questions/40631/setting-up-a-kiosk-with-chromium
 


----


[Retour à l'organisation de la création](.)
