# Core V 0.1

## Description générale

Core est un robot chef d'orchestre. Il donne le tempo à toutes les autres créatures artificielles du Labo.

![CORE V0](/ressources/divers/CORE_V0.1.jpg)

Le cerveau de Core


## Description technique

### Patch

#### Trig <-> OSC

Le server OSC (raspberry) dispose de 4 entrées et de 2 sortie trig (mini-jack) ainsi que d'une sortie ethernet (RJ45). Son rôle est de dispatcher les trig à differentes adresses IP sous forme de messages OSC et viceversa. 

### Réseau

Core est une machine pour synchroniser et mettre en reseau toutes les machines du Grim.

Voilà le schéma du réseau :

![grim-network](/ressources/divers/grim-network.png)

(source : [grim-network.dia](/sources/dia/grim-network.dia))

- Foot, Jimi et Echo sont des robots en arduino avec un entrée gate
- Lucy et Alan des robots qui fonctionne en raspberry ou PC.
- SEQ = [doepfer A 157-1/2/3](http://www.doepfer.de/a157.htm)
- CLK = [Clock O'Pawn Shakmat Modular](http://www.shakmatmodular.com/products/cop.html)
- OSC SERVEUR = Raspberry Pi
- Mod = Synthé modulaire
- PD = pure date sur un Raspberry pour synthèse sonore
- OGN/OGN VIEW = Sur un PC + un Raspberry, [OGNON](https://github.com/LeonLenclos/Ognon), logiciel de création d'animation en temps réel.


### Electronique

- Un commutateur 8 ports (e.g. *Switch réseau Gigabit RJ45 Netgear ProSAFE GS108GE 8 ports*)
- Un générateur d'horloge 
- Un sequenceur trig
- Un raspberry qui dispatche du OSC sur du Trig et vice versa

### Software

Le serveur écoute les message OSC de type `/trig/ n` et envoie un trig sur la sortie `n`.

Le serveur écoute les trigs sur ses entrées et envoie les messages correspondants sur sa table de dispatch. Voir le [code](  turing-test/sources/python/trig-to-osc.txt)

#### Table de dispatch

indique quel message envoyer à quelle adresse ip en fonction des trigs qu'il reçoit

Par exemple : 

```
IN-1 => 10.0.0.2:50460 => /control/navigator/run/ default
IN-2 => lucy.local:4242 => /dance
```
un trig sur l'entrée 1 envoie un message OSC d'adresse `/control/navigator/run` avec l'argument `'default'` à la machine `10.0.0.2` sur son port `50460`.

un trig sur l'entrée 2 envoie un message OSC d'adresse `/dance` avec à la machine `lucy.local` sur son port `4242`.


## Améliorations envisagées

- Centraliser les alims

## Moment envisagé pour la construction et/ou les améliorations.

Du 15/3/2019 au 31/3/2019 à Graulhet puis résidence 104 du 15 au 21 avril 2019

[Retour à la liste des robots du laboratoire](.)

## Logistique

Petit fly rack avec une pochette intégrée dans laquelle :
    - cables RJ45
    - 2 alim netgear
    - 1 alim rbpi
    - 1 alim modulaire
    - La doc