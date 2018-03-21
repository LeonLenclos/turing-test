# Foot

Foot, le Robot qui souffre.

[évoqué ici](../scenes/anthropomorphisme.md)

## Esthétique, allure du robot

Une boite en carton. Simple.
C'est tout...
Une simple boite en carton.

Dans l'hypothèse où un dessin est réalisé par Léon à chaque représentation sur le carton, il faut réfléchir à une solution durable (Craft collé ? )

Comme le carton doit recevoir des chocs, il faut éviter qu'il se désagrège et que l'électronique embarquée se détériore. On peut pour cela envisager une structure alu légère.

La souffrance du robot peut être aussi induite par des soubresauts ou des tremblements qui pourrait être obtenus avec un moteur entrainant un disque dont le centre de gravité est décentré.

## Matériaux envisagés

- profilés alu
- Du carton
- Un module arduino
- Un micro contact
- Un ampli et un haut parleur
- un moteur
- des accumlateurs

### Modularité
- il y a une sortie son, si on veut le brancher sur autre chose que le haut parleur intégré
- il y a une entrée qui doit etre un signal standard du spectacle et qui signifie "on me frappe à telle intensité"

## Moment envisagé pour la construction
Usinotopie mars 2018

## Hypothèses de construction, description technique

Voila un exemple de code Arduino qui allume une led quant un micro contact piezo capte un coup dont l'intensité dépasse une valeur seuil. Très facilement modifiable pour que les enregistrements de cris soient "proportionnels" au coup détecté.


   http://www.arduino.cc/en/Tutorial/Knock
