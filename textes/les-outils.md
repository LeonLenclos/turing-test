Les outils
==========

Type
----

Note d'intention

Résumé
------

Reflexion sur la nature des outils que nous utilisons pour produire des sons et des images.

S'emparer de ses outils
-----------------------

L'avènement des nouvelles technologies incite plus que jamais les artistes à s'interroger sur leurs outils. Un dessin fait avec photoshop n'est pas moins un dessin qu'un autre réalisé au crayon. Mais alors, quelles différences il y a entre les deux ? On parle de musique assistée par ordinateur (MAO) mais pourquoi ne dis-t-on jamais d'un violoniste qu'il fait de la  musique assistée par intrument à corde ?

En vérité il n'y a aucune différence essentielle entre un outil numérique et un outil analogique ou mécanique. Il y a toujours deux forces qui se confrontent lorsqu'on uttilise a des fins artistiques un outil, quel qu'il soit. D'un côté l'outil facilite la tache que l'on doit accomplir, de l'autre il nous enferme dans un cadre de possibilités restreint. Un crayon permet de dessiner beaucoup plus facilement que l'on ne peut le faire avec son doigt sur le sable mais il ne permet de faire rien d'autre qu'un dessin au crayon. L'uttilisation d'un logiciel de dessin offre une grande liberté mais jamais ce que l'on produira avec ressemblera à autre chose qu'à un dessin fait avec ce logiciel.

Il suffit alors d'avoir conscience de ce qu'un outil nous permet et de ce en quoi il nous formate. De choisir ses outils en conséquences. D'aller, quand c'est interessant, à contre sens de l'uttilisation attendue de l'outil. De modifier ses outils et, quand c'est necessaire, de les concevoir.

Si l'uttilisation de logiciels libre (open source) est importante pour certains artistes. C'est que la philosophie du libre implique une reflexion sur l'outil. Un logiciel comme Photoshop est une propriété de la marque Adobe et l'on ne fera jamais autre chose avec que ce qu'Adobe a prévu pour nous. Un logiciel comme GIMP, très similaire en apparence, est ouvert : on peut voir comment il marche et donc, potentiellement, on peut le le transformer en ce qu'on veut qu'il soit.

Dans Turing Test, les machines, programmes et instruments que nous uttilisons dans les phases de production de dessin-animé et de musique sont assez different mais témoignent d'une sensibilité que nous partageons à propos de la question de l'outil.

![](../ressources/dessin12.png)

Fabien et Pure Data
--------------------

Pure Data (Pd) est un logiciel libre de programmation graphique orienté vers la création musicale et multimédia en temps réel écrit par M. Puckette. Il permet de faire transiter des informations entrantes le long de liens matérialisés dans l'interface graphique par des lignes reliant différents objets. Chaque objet permet d'agir sur l'information entrante et ainsi de délivrer une nouvelle information, de l'aiguiller, de la traiter, de la modifier … la possibilité pour chacun de créer ces propres objets permet de prolonger à l'infini la liste des objets existants.

Dans le cadre de Turing Test, j'utilise Pd pour créer des instruments électroniques numériques et interactifs. Je contrôle en direct certains paramètres du code grâce à des dispositifs hardware (contrôleurs midi, pads de batterie électronique etc...)
L'utilisation de Pd s'imposait pour deux raisons :

-  Le rapport de l'homme à la machine que nous souhaitons défendre ici est celui de l'augmentation de la puissance créatrice de l'homme par la machine, par opposition à l'aliénation de l'homme par la machine. Ainsi ce rapport est envisagé du point de vue du bricoleur pour qui la fonction d'un outil n'est jamais entièrement fixée et peu donner lieu à tout moment à un usage nouveau. En créant mon propre synthétiseur avec Pd, le musicien-codeur définit à sa guise une zone de liberté sonore à l'intérieur de laquelle la machine évoluera plus ou moins aléatoirement. En direct, je modifie les contours de cette zone de liberté en fonction de mon inspiration dans le but d’interagir avec les autres improvisateurs présents sur scène.
-  Le code (ou « patch » par analogie avec les synthétiseurs modulaires) c'est à dire le câblage des différents objets entre eux est projeté sur l'espace scénique. Ainsi le code qui génère le son ainsi que les modifications que j'y apporte au fur et à mesure sont visibles en temps réel à la manière d'une machine dont on aurait soulevé le capot. Des interrupteurs s'allument, des glissières bougent, des formes d'ondes se dessinent au rythme de l'évolution de la musique, rendant ainsi visible à la fois le travail de bricoleur à travers l'organisation approximative des différents modules que j'ai créé, et celui de musicien par la transposition graphique des modifications sonores que je commande.


Léon et Ognon
--------------

Ognon est un logiciel de déssin animé 2D que j'ai développé en Python. Il a été créé au départ pour me permettre de réaliser facilement des animations très simple en noir et blanc que d'autres logiciels me permettaient de faire de manière compliqué. Pour répondre aux besoins du spéctacle, le logiciel a été augmenté pour permettre la réalisation d'animations en direct. Il permet de déssiner et d'animer sous les yeux des spéctateurs, sans que ceux-ci ne voient l'interface du logiciel. Il permet aussi de synchroniser la lecture des animations au rythme de la musique. Le fait d'avoir créé ce logiciel et donc de comprendre son fonctionnement dans les moindre détails permet de l'adapter aux besoins du spectacle.

Bertrand et le Synthé Modulaire
-------------------------------

Mon synthétiseur modulaire est un objet physique composé de modules élémentaires (générateur de sons, générateur de notes, filtres, ampli, mélangeur, etc) que l'on connecte entre eux avec des câbles pour créer de la musique électronique. L'intérêt de cet instrument réside dans le fait que l'on peut personnaliser le choix des modules, les relier de façon totalement libre et obtenir ainsi un instrument unique propre à générer des textures sonores originales. Ce principe permet à des milliers de petits fabricants de proposer sur le marché des modules singuliers et permet aux musiciens de s'affranchir des grands groupes industriels qui ont tendance à formater le design sonore de leurs synthétiseurs pour des raisons commerciales (Roland, Korg, Yamaha, Akay, Kurzweil, Moog, etc… ). Un des premiers modules dont j'ai fait l'acquisition s'appelle TURING MACHINE. Il est fabriquée par Tom Whitwell de Music Thing. L'intérêt de ce module et qu'il génère de façon pseudo-aléatoire des notes et des rythmes en fonctions de contraintes établies par l'interprète : degré d'aléatoire, influence cyclique, etc. Ce module m'a ouvert la porte de la musique générative. Le synthétiseur modulaire acquiert alors une sorte d'autonomie créative et produit une forme musicale non-déterministe qui s'invente perpétuellement et ne peut être répétée. Une forme primaire d'intelligence musicale ?
