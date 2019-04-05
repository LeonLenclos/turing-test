Notes Techniques
================

## Les cables <3

### Longs cables (Standard Grim)

Les longs cables passent si possible par le haut.

- Audio = XLR
    - Table <--> Moduber
    - Table <--> MS20
    - Table <--> Godel
    - Table <--> 
- Ethernet = RJ45
    - Core <--> Alan (25m)
    - Core <--> Lucy (15m)
    - Core <--> Godel (15m)
    - Core <--> Ottomann (15m)
    - Core <--> Ail (10m)
- Trig/Gate/CV = MiniJack
    - Core <--> Moduber
    - Core <--> SQ1 ?
    - Core <--> Echo
    - Core <--> Jimi
    - Core <--> Foot ?
    - Core <--> Dedo

### Alims

- 5V = USB
- Arduino Secteur
- LIPO = Connecteurs comme dans ALAN

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
