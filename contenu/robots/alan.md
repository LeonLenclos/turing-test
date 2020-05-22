# Alan v1.5.2

![alan](/ressources/photos/ALAN_104_1_CROP_SMALL.jpg)

Alan est le robot sur le quel nous avons passés le plus de temps. Encore aujourd'hui, c'est le robot que nous continuons le plus à améliorer.

Vous pouvez le rencontrer en ligne à cette adresse : [alan.cienokill.fr](http://alan.cienokill.fr)

## Description générale

Alan est un agent conversationel. C'est un robot spécialisé dans la communication verbale, conçu pour donner l'illusion d'être conscient.

Il a été créé avec la collaboration de l'[IRIT](https://www.irit.fr/) (Institut de Recherche en Informatique de Toulouse) et plus particulièrement des équipes de recherche SAMoVA et MELODI.

![irit](/ressources/photos/irit.JPG)

La compagnie et ses collaborateurs à l'IRIT.

![dessin1](/ressources/dessins/dessin1.png)

## Allure

Structure d'aluminium conçue pour être *assise* sur une chaise. La structure se replie sur elle-même pour former un parallélépipède rectangle qui se range facilement.

![alan_structure](/ressources/photos/ALAN_STRUCTURE_SMALL.jpg)

Dans la structure sont fixés les éléments du hardware.

## Matériaux 

Barres d'aluminium de section rectangulaire, matériel informatique.

## Description technique

### Hardware

Carte mère (avec le processeur et la carte graphique fixés dessus), refroidisseur, alimentation, boutons de façade et écran fixés dans la structure.

### Software

[Le dépôt github de Alan](https://github.com/LeonLenclos/alan) est consacré au code source d'alan.

Une grande partie de l'architecture d'Alan est basée sur le package python [chatterbot](https://github.com/gunthercox/ChatterBot). Le programme d'Alan est ainsi composé de modules, des bouts de programmes (appelés adapter) qui répondent à des taches précises.


#### Comment ça marche ?

##### Trouver la meilleure réponse à un message.

Le message de l'interlocuteur est d'abord traitée par des **preprocesseurs**, ces derniers effectuent quelques modifications sur le message pour le préparer et l'uniformiser.

Viens ensuite le tour des **logics adapters** dont le rôle est de construire la réponse. Le programme envoie une premère fois le message à tous les logics adapters pour leur demander s'ils pensent pouvoir trouver une réponse. Chaque adapter a une méthode **can process** qui permet de répondre à cette question.

Une fois qu'il a fait la liste de tous les logics adapters capables de répondre, il leur envoie de nouveau le message pour qu'ils construisent une **réponse**. La réponse est accompagnée d'un **indice de confiance** fournit par chaque logic adapter pour indiquer à quel point il considère sa réponse comme satisfaisante.

Le progamme choisi ensuite la réponse avec le meilleur **indice de confiance** et la retourne à l'interlocuteur.

##### Les logics adapters en détail.

Il y a actuellement plus de 60 logics adapters.

Chaque adapter a un rôle défini et possède ses propres techniques pour trouver une réponse et y attribuer un indice de confiance.

###### Un exemple simple : le logic adapter *catch-human-repetition*

Le rôle de cet adapter est de repérer si l'interlocuteur se répète. Lorsque l'interlocuteur dit deux fois de suite la même phrase, il propose une réponse du genre "Tu viens de me dire ça.", Si l'interlocuteur dit une phrase qu'il a déjà dit dans la conversation il répond, par exemple "Tu m'as déjà dit ça tout à l'heure." mais avec un indice de confiance deux fois plus faible.

###### Les Rive Script Adapters

Plus de la moitié des logics adapters sont des **Rive Script Adapters**. Ils trouvent une réponse en utilisant des scripts écrit avec le langage [RiveScript](https://www.rivescript.com/). Ce langage a été conçu spécialement pour programmer des chatbots. Il permet de traiter simplement beaucoup de variation de messages et de générer des réponses personnalisés. 

Par exemple, ce bout de code RiveScript

   + j'aime le _
   - Moi je n'aime pas le <star>
   - Moi aussi j'adore le <star>

Permet de répondre à une phrase comme "J'aime le sport" en choisissant au hasard une réponse entre "Moi je n'aime pas le sport" et "Moi aussi j'adore le sport". Mais il marchera de la même manière avec les phrases "J'aime le rhum", "J'aime le printemps", "J'aime le brlghtkmkh", etc.

Les Rive Script Adapters travaillent avec des fichiers contenant des centaines de lignes de RiveScript faits pour traiter tout un ensemble de message souvent liés à un thème ou à un type de phrase. Par exemple, le Rive Script Adaper *art* traite les questions et les afirmations de l'interlocuteur se raportant aux arts et à la carrière artistique de Alan.

###### Calculer les indices de confiance

La plus-part des adapters ont un indice de confiance fixe. On donnera des bons indices de confiance à des adapters quis se déclanchent rarement mais sont toujours pertinents et des faibles indices de confiance à des adapters qui se déclanchent toujours mais sont en général peu pertinents. Cet équilibre est très important. Nous devons travailler sur des adapters de confiance qui vont impressionner l'interlocuteur avec leur pertinance, mais comme ils couvreront toujours un petit spectre de message il est important d'avoir en dessous des adapteurs de faible confiance qui donnent des réponses larges, tentent d'esquiver la question ou de changer de sujet.

Sur certains logic adapters nous utilisons des indices de confiance dynamique. Par exemple, le logic adapter *salutations* qui s'occupe des "Bonjour", "Comment ça va", "Comment tu t'appelle", etc. a un bon indice de confiance en début de conversation et il diminue par la suite. Certains adapters (comme le *catch-human-repetition* évoqué plus haut) sont aussi capable d'adapter leur indice de confiance en fonction du contexte.

Voici un tableau qui repertoriais tous les logics adapter et leur indice de confiance au début du développement :

![alan_logic](/ressources/photos/alan_logic.JPG)


###### Le Mode Impro 

Un des logics adapters, **mvo chatbot adapter** utilise un programme développé par Michael Vo dans le cadre de notre partenariat avec l'IRIT. C'est adapter n'est chargé qu'en spectacle et il s'occupe de ce que nous apelons le **Mode Impro**.

Cet adapter utilise des méthodes d'apprentissage profond (réseau de neuronne) pour créer des réponses originales grace à un corpus de sous-titre de film.

##### Entrées/Sorties

En plus des preprocesseurs et des logics adapters, d'autres modules ont un rôle important dans le fonctionnement d'Alan. Ce sont les **Input Adapters** et les **Output Adapters** ils s'occupent respectivement de gérér la reception des messages de l'interlocuteur et le renvoie de la réponse.

##### Storage

Le dernier type de module que l'on trouve dans Alan s'appelle **Storage Adapter**. Son rôle est essentiellement d'enregistrer la conversations dans une base de donnée. Mais certains logics Adapter s'en server pour stocker d'autres informations. Par exemple, si Alan vous demande "C'est quoi une pomme ?" et que vous répondez "C'est un fruit", il stockera cet information dans la base de donnée pour pouvoir être capable de dire que "Une pomme est un fruit" dans une future conversation.

##### Differents réglages

Un des avantage de ce système est sa modularité. En fonction du contexte dans le quel on lance Alan, on peut charger differents adapters. Par exemple, en spectacle on charge le Output Adapter qui permet de produire la synthèse vocale à Alan. Mais sur internet on ne le charge pas. De la même manière, certains logics adapter ne sont chargés que pour le spectacle, mais pas quand on fait converser Alan au public.

Nous utilisons principalement quatre réglages different : **spectacle**, **local**, **internet** et **default**


##### Client/Server

Un dernier point important du fonctionnement d'Alan est l'architecture client/server. Nous l'avons au départ développé pour avoir un meilleur control sur l'interface d'Alan en spectacle mais elle s'est ensuite avérée essentielle pour la mise en ligne.

L'idée est de séparer le programme en deux :

- d'un côté la partie **client** qui s'occupe de tout ce que l'on a sous les yeux lorsque l'on parle avec Alan, afficher une page, y afficher la conversation, permettre à l'utilisateur d'entrer des messages, etc. 
- de l'autre coté, il y a le **server**, il contient l'essentiel du programme (tout ce qui est expliqué ci-dessus). Le client informe le server des phrases entrées par l'utilisateur et il lui demande quel est l'état de la conversation.

Lorsque vous parlez avec Alan en ligne, la partie *client* est chargé par votre ordinateur. Mais la partie *server* tourne chez nous.



#### Organisation du dépot d'Alan


[Le dépôt git de Alan](https://github.com/LeonLenclos/alan) contient differentes versions du projets dans ce qu'on appelle des **branches**

- La branche **master** contient la version la plus stable d'Alan mais aussi la moins recente. C'est la version qui est utilisée sur scène. Nous la mettons rarement a jour de peur que des bugs qui nous auraient échapés surgissent en pleine représentation.

- La branche **internet** contient la version d'Alan avec la quelle on peut discuter en ligne, l'ordinateur sur lequel Alan est hebergé télécharge la version la plus recente de cette branche toutes les nuits à 4h.

- La branche **develop** est la branche sur la quelle nous travaillons, lorsque nous estimons qu'elle est prête nous l'utilisons pour mettre à jour la branche *internet*. Et quand nous en somme vraiment fier, nous faisont une *release* pour mettre à jour la branche *master*

## Intentions


A une époque où la frontière entre le monde virtuel et l'IRL (la [vraie vie](https://fr.wikipedia.org/wiki/Vraie_vie)) est de plus en plus [difficile à tracer](https://books.google.ca/books?id=VwJ4xsYHboYC&pg=PA533&lpg=PA533&dq=%22Social+Relationships+and+Identity+Online+and+Offline%22&source=bl&ots=bpBvupth9B&sig=2JeW2bC5x0yakE8JZNXGNCobemY&hl=en&sa=X&ei=0l5CUaaxDdPE4AO-_IHACg&ved=0CDgQ6AEwAQ#v=onepage&q=%22Social%20Relationships%20and%20Identity%20Online%20and%20Offline%22&f=false), Alan incarne l'irruption du numérique dans le quotidien tout autant que le décloisonnement du spectacle. Une oeuvre n'est jamais définitivement enfermée dans un temps et un lieu. La communication qui est faite autour d'une performance ainsi que les discussions et les réactions qu'elle suscite en font partie intégrante. Alan participe à cet étalement du spectacle dans l'espace-temps. Il est éveillé sur scène, avant et après le spectacle, il peut participer aux discussions, aux débats et même aider à évacuer les gens si jamais l'alarme incendie vient à sonner.



## Grandes étapes de la construction et du developpement d'Alan

- Résidences de programmation à l'IRIT au printemps 2018.
- Montage et fabrication du hardware à l'usinotopie (mars 2018) et à Bessines (octobre-novembre 2018).
- Résidence au quai des savoirs du 16 au 21 novembre 2018 pour une confrontation au public et pour avancer sur les améliorations en vue de la version 2.0.0 .
- Améliorations suite à la mise en ligne d'Alan au printemps 2020.

![](/ressources/photos/alan_software.JPG)


[Retour à la liste des robots du laboratoire](.)
