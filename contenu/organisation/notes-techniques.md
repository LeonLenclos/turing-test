Notes Techniques
================

## Les cables <3

### Longs cables (Standard Grim)

- Audio = XLR
- Ethernet = RJ45
    - Core --> Alan = 25m
    - Core --> Lucy = 15m
    - Core --> Godel = 15m
    - Core --> Ottomann = 15m
    - Core --> Ail = 10m
    - cable de patch = 15cm
    - cable de patch = 10cm
- Trig/Gate/CV = MiniJack

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

Mesures prises à Bessines
Profondeur minimale: 6m
Largeur minimale: 7,75m
Hauteur minimale 3m 

----


[Retour à l'organisation de la création](.)

## Réseau

Les machines connectées au réseau :
- Thinkpad de Léon pour Ognon : ottomann.local (10.0.0.2)
- Raspberrypi de Fab pour Puredata : 
- Core : core.local (10.0.0.11)
- Lucy : lucy.local (10.0.0.13)

## Ail

Le rpi qui diffuse ognon

- est mis en vertical grace à une ligne dans `/boot/config.txt` (https://www.raspberrypi.org/forums/viewtopic.php?t=120793)
- lance chrome au demarrage grace au contenu de `/home/pi/.config/lxsession/LXDE-pi/autostart` https://raspberrypi.stackexchange.com/questions/40631/setting-up-a-kiosk-with-chromium
