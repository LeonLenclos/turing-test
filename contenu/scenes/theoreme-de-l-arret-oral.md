Théorème de l'arrêt
===================

Fabien explique le Théorème de l'arrêt à Léon 

- Ce que tu voudrais c'est piéger le programme S avec le programme delta
- On va donc faire boucler delta(x) si S(x,x) est égal à 1
- Et faire s'arrêter delta(x) si S(x,x) est égal à 0
- L'argument diagonal va consister à appliquer delta sur delta lui-même
- Donc soit le programme delta de delta boucle, soit il s'arrête.
- Supposons que delta de delta boucle:
  si delta de delta boucle, S(delta, delta) est égal à 1
  mais si S(delta, delta) est égal à 1 alors delta de delta s'arrête
  Si je boucle je m'arrete, ce qui est absurde. Donc delta de delta s'arrête
- Mais si delta de delta s'arrête , S(delta,delta) est égal à 0
  Donc delta de delta boucle
- Si je m'arrête je boucle et si je boucle je m'arrête!
- Contradiction !

![théorème de l'arrêt](/ressources/divers/theoreme_de_l_arret.jpg)
