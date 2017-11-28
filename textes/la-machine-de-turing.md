La machine de Turing
====================

Type
----
Texte théorique

Résumé
------
Retour sur le concept de machine de Turing, sur le contexte de son invention et sur certains liens entre informatique et mathématiques.


Citation
--------
 > We may compare a man in the process of computing a real number to a machine...
 
 [Alan Turing](http://www.thocp.net/biographies/papers/turing_oncomputablenumbers_1936.pdf)

Définition
-----------

Une machine de Turing est une machine idéale composée :
-  d'un ruban de longueur infinie découpé en cases à l'intérieur desquelles peuvent être écrits un nombre fini de symboles (les entrées). Il n'y a qu'un nombre fini de symboles possibles (0 et 1 suffisent).
-  d'une tête à la fois de lecture et d'écriture qui lorsqu'elle est placée devant un symbole peut le lire, l'effacer ou le remplacer par un autre symbole et ensuite se déplacer d'un symbole vers la droite ou vers la gauche.
-  d'un nombre fini d'états dans lesquels peut se trouver la machine
-  d'une table de transition qui dicte à la machine, étape par étape, ce que doit faire la tête et dans quel état doit passer la machine en fonction de l'état et du symbole lus à l'étape précédente.

![](../ressources/dessin9.png)

Propriétés
----------
-  Finitude
-  Localité
-  Déterminisme

Différences entre une machine de Turing et un ordinateur
--------------------------------------------------------

Pour beaucoup l'invention en 1936 des machines de Turing signe la naissance de l'informatique moderne. On s'imagine facilement le jeune Alan Turing branchant les derniers cables sur une armoire immense remplie de rotors et de boutons et criant eurêka. On en oublierait presque qu'une machine de Turing n'est qu'un concept abstrait, mathématique, la définition d'une machine idéale et parfaite que Turing a écrite dans un article.

On peut bien évidemment fabriquer une machine de manière a ce que son fonctionnement suive les principes d'une machine de Turing mais ça n'en sera jamais vraiment une.
Il est assez facile de se rendre compte de ça :
Prenons un ordinateur portable quelconque, je peux par une astucieuse manipulation informatique modifier son fonctionnement et l'utiliser pour réaliser des opérations qu'une machine de Turing, de par sa nature conceptuelle, ne pourra jamais réaliser.

Je peux par exemple me protéger de la lumière du soleil, en m'en servant de chapeau ou encore m'en servir comme d'une planche à découper.

Une machine de Turing ne pourra jamais faire cela. Au premier abord on se dit que du coup un ordinateur est mieu qu'une machine de Turing. Mais en fait ce n'est pas toujous vrai. Si vous faites faire une addition à une machine de Turing, elle vous donnera toujours le bon résultat. Alors que même pour une addition très simple comme 2+2, un ordinateur peut s'avérer incapable d'effectuer l'addition correctement. Cela reste quant même assez rare, mais on a toujours une image erronée de l'ordinateur qui ne se trompe jamais et ça c'est complétement faux.

 Si j'ouvre le programme "calculatrice" sur mon ordinateur portable, que je tape 2+2 et que je met ensuite un coup de masse sur l'ordinateur, j'aurais beau appuyer sur la touche égale, l'ordinateur a peut de chance de me donner la bonne réponse.

La notion de calcul
-------------------

Ce qui est drôle dans l'invention de la machine de Turing c'est que, à cette époque, il n'existait pas de machine numérique qu'on puisse programmer pour faire des calculs, mais on pouvaitt tout à fait imaginer que le calcul soit mené par un humain. En fait il existait même des bureaux de calculs dans lesquels les gens passaient leurs journées à faire des calculs pour l'armée ou pour les scientifiques. Ces bureaux sont finalement autant des machine de Turing que les ordinateurs modernes, bien que ces derniers fassent moins d'erreurs. Finalement c'est la 2nde guerre mondiale qui a accéléré le développement des premiers ordinateurs, mais même dans les années 50, les ordinateurs étaient encore ridiculement lents. 

Quant en 1952 Turing invente un programme capable de jouer aux échecs, aucun ordinateur n'est assez puissant pour l'exécuter. Du coup Turing est obligé de simuler lui-même le comportement d'un ordinateur, et il arrive ainsi à jouer une partie contre un collègue en effectuant lui-même les calculs. 
Malgré le fait qu'il mette environ une demi heure pour effectuer tout les calculs et savoir quel coup jouer et le fait qu'il ait finalement perdu la partie, cela  force l'admiration.


Bien évidemment Turing a toujours révé de construire des machines à calculer et il le fera plus tard dans sa vie, mais ce n'est pas vraiment pour ça qu'il a inventé le concept de machine de Turing. La machine de Turing était censée être un modèle du comportement d'un humain en train de mener un calcul. En fait en 1936 Turing n'invente pas l'ordinateur, il définit ce qu'est un calcul ou un algorithme. Il n'est pas le premier, d'autres mathématiciens comme K.Gödel ou A.Church on déja travaillés à définir rigoureusement la notion intuitive de calcul, mais la définition que donne Turing, bien qu'elle soit relativement équivalente à celles déja existantes, est donnée sous une forme particulièrement intuitive et générale. 
Mais pourquoi se préoccupe-t-on tant de définir ce qu'est un calcul ?

Calculs et démonstrations
-------------------------

Pour comprendre l'importance de la notion de calcul, il nous faut faire un peu d'histoire des mathématiques. Très tôt les mathématiques ont adopté la forme axiomatique, les éléments d'Euclide écrits en 300 avant notre ère en sont un exemple de démarche axiomatique dans le domaine de la géométrie. L'idée pour être sur que quelque chose, un théorème par exemple, est vrai, et qu'on ne peut pas le mettre en doute est la suivante :

On énonce quelques propositions qui sont évidentes, que personne ne met en doute, ce sont les axiomes. Puisque l'on est tous d'accord sur ces points de départ, on sera d'accord sur tout ce que l'on pourra déduire de ces axiomes. La déduction ou démonstration, doit se présenter étape par étape de manière à ce que tout le monde puisse vérifier sa validité. Chaque étape doit être elle aussi évidente, aller de soi en quelque sorte.
Au fil des siècles et de l'apparition de nouvelles disciplines des mathématiques de nouveaux systèmes axiomatiques aparurent comme les axiomes de Peano pour l'arithmétique. Au XIXème siècle G.Cantor inventa la notion d'ensemble, une notion extrêmement puissante et générale. Mais au début du XXème siècle un séisme secoua les mathématiques, c'est ce que l'on apellera plus tard "la crise des fondements" et son épicentre était la théorie des ensembles de Cantor. On se rendit compte que la définition que donnait Cantor d'ensemble, bien qu'elle paraisse évidente et indubitable, menait à des paradoxes. On pouvait démontrer à la fois quelque chose et son contraire, ce qui est facheux.

Heureusement un homme, le grand mathématicien D.Hilbert, avait la solution. On ne pouvait pas faire confiance à son intuition pour reconnaitre les évidences, il fallait donc réduire au strict minimum ce qu'on reconnaissait comme indubitable et supprimer toutes le reste. Hilbert, fin observateur, avait remarqué que l'homme avait la capacité de communiquer à travers le langage. De cette possibilité, il déduisit le fait que nous avions effectivement une "intuition du signe", que nous étions capables de manipuler des symboles. Il émis ainsi le projet, connu sous le nom de Programme de Hilbert, de fonder la vérité de tout énoncé mathématique sur une manipulation fini de symboles, autrement dit un calcul ou un algorithme. Ce point de vue concernant la méthode axiomatique est appelé le formalisme. 

Dans une théorie axiomatique formelle, au lieu d'avoir des axiomes et des déductions évidentes, on a des axiomes qui ne sont rien de plus que des suites de symboles que l'on a pas le droit d'interpréter et qui n'ont aucun sens et des règles de transformations valides qui nous permettent de transformer les suites de symboles. On peut appliquer des règles de transformations, en ajoutant, en enlevant ou en substituant certains symboles aux axiomes pour avoir d'autres suites de symboles. Une démonstration n'est alors rien d'autre qu'une suite d'axiomes et de transformations successives de ces axiomes, jusqu'à arriver à la dernière suite de symboles qui est le théorème. La force de ce programme c'est que on ne peut vraiment pas douter de la justesse d'une démonstration parce que même une machine peut vérifier si la démonstration est valide ou pas. Le concept de machine de Turing était une manière de préciser ce que Hilbert entendait par calcul ou manipulation de symboles et d'étudier la faisabilité de son projet.

Le problème esprit\machine et les théorèmes de Gödel
----------------------------------------------------

Donc si l'on donne une démonstration formelle à une machine de Turing, elle est capable de dire si elle est correcte. Pour Hilbert il serait alors possible de trouver un algorithme qui soit capable de démontrer ou d'infirmer n'importe quel théorème mathématique. L'algorithme marcherait ainsi : on lui donnerait en entrée un théorème mathématique et il sortirait la démonstration de ce théorème s'il est vrai, et sinon il sortirait la démonstration de sa négation. Turing introduit le concept de machine de Turing afin de prouver qu'une telle machine ne peut pas exister.

Ce n'est pas le seul revers que subit le programme de Hilbert. En 1931, quelques années auparavant, le jeune mathématicien et logicien K.Gödel par ses théorèmes d'incomplétude avait déja mis fin au programme de Hilbert, l'article de Turing s'appuie d'ailleurs largement sur ces théorèmes. Gödel avait prouvé que si on réduisait les mathématiques, ne serait-ce que l'arithmétique, a des axiomes formels, on ne pourrait jamais prouver dans ce cadre là que l'arithmétique était cohérente. C'est à dire que Hilbert ne pourrait jamais être sur qu'un beau jour on puisse démontrer que 2+2=3 dans son système, ou plutôt s'il en était sur, cela ne pouvait pas lui venir uniquement de la manipulation de symboles. Ainsi un ordinateur peut effectuer la somme 2+2 de millions de manières différentes, mais il ne pourra jamais être sur que le résultat sera toujours le même, il est incpable de déduire cela de son propre fonctionnement. De plus Gödel avait prouvé que même dans le cas où un système d'axiomes serait cohérent, il y aurait toujours des énoncés vrais qu'on serait incapable de démontrer à l'intérieur de ce système, et ce quelque soit les axiomes choisis, tant qu'on ne les considérait que comme des suites de symboles.

Gödel tira 1951 une conclusion de ces théorèmes d'incomplétude : Soit il existe des vérités mathématiques qui ne peuvent êtres démontrées par aucun esprit humain soit l'esprit dépasse les capacités mathématiques d'une machine de Turing.

En 1933, A.Tarski s'appuya sur les résultats de Gödel pour énoncer un théorème aux conséquences surpenantes : On ne peut établir la vérité des énoncés d'un langage formel à l'intérieur de ce langage. 
Une de ces conséquences est que le [paradoxe du menteur](https://fr.wikipedia.org/wiki/Paradoxe_du_menteur) est résolu puisqu'on montre qu'il n'a en fait aucun sens.
On a souvent l'impression que si notre esprit n'était rien d'autre que le résultat de l'exécution d'un algorithme, cela casserait en quelque sorte le charme et le mystère de l'esprit. On s'imagine effrayés qu'il serait alors possibles de modifier cet algorithme pour l'améliorer et créer ainsi un esprit qui dépasse l'esprit humain. Seulement d'après le théorèmes de Tarski, si notre cerveau est effectivement une machine de Turing, il nous serait impossible en un certain sens d'avoir du recul par rapport à notre algorithme-esprit. Si notre sens de ce qui est vrai (comme le fait que 2+2=4) est géré par un algorithme, on ne saura jamais si c'est effectivement vrai et pourquoi c'est vrai. Si notre esprit est un algorithme, soit on est incapables de le connaitre, soit le connaitre ne nous servirait à rien car on ne pourrait rien en dire de plus que ce que nous poussait à croire cet algorithme quant nous ne le connaissions pas.

Conclusion
----------

Les résultats mathématiques évoqués dans la dernière section invitent à une réflexion sur l'autoréférence. De nombreux artistes ont senti qu'il y avait là une notion qui invitait à une réflexion profonde comme par exemple Escher dans sa litographie [Drawing hands](http://www.mcescher.com/gallery/back-in-holland/drawing-hands/). Les paradoxes qui ont provoqués et motivés ces théorèmes exploitent largement l'autoréférence. Pourtant l'autoréférence n'est pas paradoxale en soi. Lorsqu'un juge dit "je vous condamne", il le vous condamne et il dit qu'il vous condame tout à la fois et cela n'a rien de paradoxal. Nul n'a besoin de dire je voit un arbre pour le voir, le juge lui ne condamne que s'il dit qu'il condamne. De la même manière je peux dire que le mot "court" est court, il y a une autoréférence mais ça ne pose aucun problème. Ce que nous dit le théorème de Tarski c'est qu'il y a une autoréférence qui est interdite, qui n'a pas de sens : celle qui exprime sa propre vérité. On a pourtant parfois l'impression que dans le domaine de l'I.A., on nous vend le dépassement de l'homme par l'homme, l'avénement d'un homme 2.0 que l'homme 1.0 aurait réussi à créer?

C'est là une chose qu'il est bon d'avoir en tête lorsqu'on cherche à créer de nos mains des êtres artificiels : Si vous êtes sur d'avoir créé une machine fiable, alors vous lui êtes forcément supérieur, car elle ne peut se rendre compte de sa propre fiabilité. 
