Notes Techniques
================

Mini caméra
-----------

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


Réseau
------

L'idée est d'avoir une machine pour synchroniser les autres machines. Et aussi permettre aux machines de communiquer.

Voilà le schéma du réseau :

![réseau grim](/ressources/grim-network.png)

(source : [grim-network.dia](/ressources/grim-network.dia))

- Foot, Jimi et Echo sont des robots en arduino avec un entrée gate
- Lucy et Alan des robots qui fonctionne en raspberry ou PC.
- SEQ = doepfer A 157-1/2/3
- CLK = Clock O'Pawn Shakmat Modular
- OSC SERVEUR = Raspberry Pi
- Mod = Synthé modulaire
- PD = pure date sur un Raspberry pour synthèse sonore
- OGN/OGN VIEW = Sur un PC + un Raspberry, OGNON, logiciel de création d'animation en temps réel.

La machine CORE contient donc :

- Un commutateur 8 ports (e.g. *Switch réseau Gigabit RJ45 Netgear ProSAFE GS108GE 8 ports*)
- Un générateur d'horloge 
- Un sequenceur trig
- Un raspberry qui dispatche du OSC sur du Trig et vice versa

Par exemple

![montage](/ressources/CORE V0.1.jpg)

