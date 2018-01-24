# Robot qui souffre

[évoqué ici](../textes/anthropomorphisme.md)

## Esthétique, allure du robot

Une boite en carton. Simple.
C'est tout...
Une simple boite en carton.

## Matériaux envisagés

- Du carton
- Un module arduino
- Un micro contact
- Un haut parleur

###Modularité
- il y a une sortie son, si on veut le brancher sur autre chose que le haut parleur intégré
- il y a une entrée qui doit etre un signal standard du spectacle et qui signifie "on me frappe à telle intensité"

## Moment envisagé pour la construction
Usinotopie mars 2018

## Hypothèses de construction, description technique

Voila un exemple de code Arduino qui allume une led quant un micro contact piezo capte un coup dont l'intensité dépasse une valeur seuil. Très facilement modifiable pour que les enregistrements de cris soient "proportionnels" au coup détecté.


   http://www.arduino.cc/en/Tutorial/Knock
