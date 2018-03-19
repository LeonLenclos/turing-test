
# Alan

## Esthétique, allure du robot

En phase de prototypage à l'usinotopie.


## Matériaux envisagés
Du fait de sa taille et des équipements hébergés (écran, unité centrale, haut parleur,...) il faut imaginer une structure à base de matériaux solides : aluminium et bois. Pour l'habillage et les formes, du plastique.

## Hypothèses de construction, description technique
Alan sera en même temps son propre rangement. Conçu en deux parties, la partie haute pourrait se ranger retournée dans la partie basse comme un couvercle de flight-case. 

### Hardware

#### Quel ordinateur ?

Pour l'instant ordinateur mac pour profiter de sa synthèse vocale en attendant de trouver une solution opérationelle sous linux.

#### Et sur internet ?

Le [code d'Alan est en ligne ici] (https://github.com/LeonLenclos/alan), il sera rendu disponible en ligne lorsque sa première phase de développement sera terminée. Lorsqu'il partira avec la compagnie pour un spectacle, il sera téléchargé sur u ordinateur et rendu indisponible en ligne. A notre retour, le code en ligne sera remplacé par le code situé dans l'ordinateur que nous auront emportés, pour qu'Alan se souvienne de chaque expérience scénique lorsqu'il est de nouveau rendu disponible en ligne.


### Software

#### Partie cerveau

Parti logiciel : programme qui tourne sous python avec le module chatterbot (Entrée sorties = textes).

Pour l'instant nous éclaircissons le fonctionnement et les possibilités de chatterbot pour pouvoir réfléchir à une stratégie de programmation qui respecte au maximum un certain nombre de contraintes (à compléter):

- Pouvoir être accessible sur internet pour apprendre du public.
- Garder un accés pas trop complexe à l'intérieur du progamme pour pouvoir controler l'évolution de Alan voire le "censurer". L'idéal serait de pouvoir le controler vocalement, de modifier l'indice de pertinence en faisant une remarque orale à Alan.
- Pouvoir basculer dans un mode spectacle plus controlé, si possible à l'oral (par exemple : "le spectacle commence" et "c'est fini le spectacle"). (possibilité de bloquer l'apprentissage pendant le spectacle https://chatterbot.readthedocs.io/en/stable/examples.html#read-only-mode )
- Savoir reconnaitre le rire (conversion audio vers texte)
- aprentissage :
    - tout au long des conversations, il garde en mémoire les Nouveaus mots, les manières de parler.
    - on peut aussi lui apprendre des choses directement (par exemple : "Un chien est un animal") 

#### Partie son (i/o)

Travailler avec l'IRIT pour la conversion audio vers texte et puis pour la synthèse vocale.

Questions liés à la compréhension et à l'expression vocale:
N'étant pas du tout familier de ces technologies, je me pose des questions concernant :

- Possibilité de reconnaitre la voix
- Possibilité de reconnaitre une question à l'intonnation. ("Tu es content." / "Tu es content ?")
- Possibilité d'identifier un rire

- Possibilité de dire des "hum...", des "OH !", des "ah ah ah !"
- Possibilité de faire des pauses

### Méthode

Methode de travail proposée :

 1. Ecrire des discussions possible avec Alan. Des discussions très simples et voir ce que ça implique comme compétences.

 2. Essayer de programmer ces compétences. C'est à dire, rendre les discussions en questions possible

Par exemple :

#### discussion :

    - Salut Alan.
    - Salut.
    - Sais tu ce que c'est un tournevis.
    - Oui, c'est un outil.
    - Sais tu ce que c'est un tournevis.
    - Tu m'as déjà posé cette question.

#### compétences impliquées :


   1. Je sais dire bonjour quand on me dit bonjour
   2. Je sais répondre à une question de type "Sais-tu ce que c'est ..."
   3. Je remarque quand on me pose deux fois la même questions.

plusieurs possibilités :

Je sais dire bonjour quand on me dit bonjour.

- Possibilité 1 : J'ai appris à répondre "Salut." à celui qui me dit "Salut Alan"
- Possibilité 2 : "Salut Alan." est dans ma liste de salutations. Je dois y répondre par une autre salutation.

Je sais répondre à une question de type "Sais-tu ce que c'est ..."

Possibilité : Je cherche si la chose est dans ma liste de concept. S'il y est, j'ai plusieurs solutions j'en choisis une au hasard parmis celle possible. Par exemple si je connais un concept équivalent je peux dire "[concept] c'est comme [concept équivalent]", si je connais la définition je peux dire "[concept] c'est [définition]", si je connais une famille de concept a laquelle il appartient je peux dire "[concept] c'est [concept parent]", etc. ()Ça implique de réfléchir à une classe Concept...)

Je remarque quand on me pose deux fois la même questions.

Je me souviens de ce qu'on m'as dit précédement. à chaque fois qu'on me dis un truc. Je regarde si on me l'a déjà dit. J'ai des phrases que je sors quand on viens de me le dire. J'ai des phrases que je sors quand on me l'as dit il y a pas longtemps. Et éventuellement j'ai des phrases que je sors parfois quand on me l'a dit il y a longtemps.

Ces réponses sont en fonction de ce qu'on me dit. (c'est une question, c'est un ordre, etc.) Ça implique que je sois capable de classer ce qu'on me dit dans des catégories.

#### Codage

Il faut ensuite coder tout ça. Plus on a été précis dans la description litéraire des algorithme (ci-dessus). Plus le travail de programmation sera facilité.

Il faut aussi des stratégie de programmation pour que tout ça soit bien rangé. Que ça ne devienne pas un gros bordel avec plein de fonctionnalités dans tous les sens. Voici quelques trucs à faire auquels j'ai pensé en lisant la doc :

- Au niveau des corpus, faire un petit programme qui nous permette d'intégrer beaucoup de texte brut d'un coup (En redécoupant les phrases, en effaçant la mise en page). Une partie de ce progamme peut être réutilisée pour faire un preprocessor qui modifie l'entrée (enleve espaces ou accents par exemple. (Travail partiellement fait par nltk, se pensher sur le problème des accents)
- Continuer à chercher des corpus (pour Einstein par exemple).
- Intégrer (?) best match adaptator et training


Des points de doc ( https://media.readthedocs.org/pdf/chatterbot/stable/chatterbot.pdf ) a commencer à regarder :


- 4.7.3.4 : permet de n'activer un logic adaptator que si un mot clé est présent dans l'entrée.
- 4.7.3.5 : permet d'aller chercher des informations à l'extérieur du bot et de les intégrer dans la réponse (météo ou encore état des autres robots s'ils sont connectés à Alan)
- 4.7.7.1 Répondre que l'on ne comprend pas quand l'indice de pertinence est au-dessous d'un seuil (faire à travers rivescript)
- 4.7.8 Si la phrase prédéfinié  est détectée, une réponse prédéfini est automatiquement donnée. (Par ex aux réponses qui est ton maitre ou qui est ton créateur, Alan sera condamné à donner toujours la même réponse, il ne pourra pas modifier sa réaction à ces questions. (faire à travers rivescript)
- 4.11 filtres : à creuser, les filtres permettent de filtrer les réponses retournés (n'accepter une réponse que si elle contient un des mots d'une liste par exemple ou bien que si elle n'a pas été prononcée récemment ...)
- 4.15.4 stopwords removal
- 4.18.2 comment mettre le chatbot en ligne


## Moment envisagé pour la construction

Software à l'IRIT, Hardware à l'usinotopie.
