
# Alan

## Esthétique, allure du robot

Je pense que contrairement aux autres robots, on n'est pas obligés d'éviter à tout prix l'anthropomorphisme pour Alan puisque c'est un robot qui a pour vocation à avoir une certaine "présence", bien sur on peut incarner cette présence de bien des manières.

Je pense qu'il faut que son "visage", la partie que l'on regarde quand on lui parle, soit à la même hauteur que le notre.



## Matériaux envisagés


## Hypothèses de construction, description technique


### Hardware

#### Quel ordinateur ?

Pour exécuter Alan, j'ai discuté avec des gens du Fablab LFO qui est à la friche et comme la reconnaissance vocale et la synthèse sont des programmes assez lourds, il vaut mieu partir sur un raspberry pi que sur un Aduino. De plus les raspberry tournent sous python contrairement aux arduinos qui fonctionnent en C.

#### Et sur internet ?

Alan doit pouvoir marcher hors-ligne. Pour les endroits ou on joue sans connexion. Il doit donc être autonome sur ce niveau là.

Je pense que le programme est à deux endroits :
- dans le robot
- sur un serveur

Lorsqu'on joue le spectacle on télécharge la version la plus récente de la base de donnée d'Alan. A la fin du spectacle la base de donnée a encore évolué, on la met en ligne à la place de l'ancienne. Cela implique que lorsque le programme vient d'être versé dans le robot, toute apprentissage qui se fera entre le moment ou on met le programme dans le robot et le moment où le programme est mis à jour sur internet à partir de l'apprentissage du robot, sera perdu (puisque pendant ce temps là en gros l'apprentissage se fait via le robot et non via internet). Peut être que la version internet peut basculer en mode "read only" et discuter sans apprendre avec les internautes tant que Alan est en spectacle. Quant le spectacle est fini, il peut de nouveau être attentif aux internautes et apprendre d'eux. Il me (Fabien) semble vraiment que c'est la solution la moins compliquée et de plus ça donne une unicité à Alan qui ne peut pas coplétement être à deux endroits en même temps.

Je ne sais pas comment on travail en python sur internet, je me renseignerai, je crois qu'il y a des solutions.


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
    - on peut aussi lui apprendre des choses directement (par exemple : "Un chien est un animal") (via une liste de conversations écrites https://chatterbot.readthedocs.io/en/stable/training.html#training-via-list-data )

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

Il faut ensuite coder tout ça. Plus on a été précis dans la description litéraire des algorythme (ci-dessus). Plus le travail de programmation sera facilité.

Il faut aussi des stratégie de programmation pour que tout ça soit bien rangé. Que ça ne devienne pas un gros bordel avec plein de fonctionnalités dans tous les sens.

## Moment envisagé pour la construction

Software à l'IRIT, Hardware à l'usinotopie.
