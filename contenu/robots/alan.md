# Alan v1.2.1

![](../../ressources/alan.JPG)

## Description générale

Alan est un agent conversationel en cours de développement créé pour le spectacle [Turing Test](https://github.com/LeonLenclos/turing-test) avec la collaboration de l'[IRIT](https://www.irit.fr/) (Institut de Recherche en Informatique de Toulouse) et plus particulièrement des équipes de recherche SAMoVA et MELODI. C'est un robot spécialisé dans la communication verbale, conçu pour donner l'illusion d'être conscient.
On peut discuter avec lui de choses et d'autres mais sa spécialité c'est la conscience de soi. Il a été programmé pour donner l'illusion qu'il est conscient d'exister.

Grâce à l'apprentissage profond, de plus en plus de chatbots sont capables de progresser en s'entrainant à converser avec des humains, Alan mémorise ainsi des concepts et des informations au détour de ces conversations. Il fait partie de cette famille de robots qui finissent un jour par échapper à leur concepteur. Grâce à l'aide de l'IRIT, Alan peut improviser des réponses en se fondant sur un apprentissage profond basé sur un corpus de répliques de films récupérées via les fichiers de sous-titres.  
Bientôt même quand il ne sera pas sur scène, Alan sera quand même là, sur le site de la compagnie, disponible pour parler avec le premier venu.
A la date suivante, Alan aura un peu changé. Comme nous.

A une époque où la frontière entre le monde virtuel et l'IRL (la [vraie vie](https://fr.wikipedia.org/wiki/Vraie_vie)) est de plus en plus [difficile à tracer](https://books.google.ca/books?id=VwJ4xsYHboYC&pg=PA533&lpg=PA533&dq=%22Social+Relationships+and+Identity+Online+and+Offline%22&source=bl&ots=bpBvupth9B&sig=2JeW2bC5x0yakE8JZNXGNCobemY&hl=en&sa=X&ei=0l5CUaaxDdPE4AO-_IHACg&ved=0CDgQ6AEwAQ#v=onepage&q=%22Social%20Relationships%20and%20Identity%20Online%20and%20Offline%22&f=false), Alan incarne l'irruption du numérique dans le quotidien tout autant que le décloisonnement du spectacle. Une oeuvre n'est jamais définitivement enfermée dans un temps et un lieu. La communication qui est faite autour d'une performance ainsi que les discussions et les réactions qu'elle suscite en font partie intégrante. Alan participe à cet étalement du spectacle dans l'espace-temps. Il est éveillé sur scène, avant et après le spectacle, il peut participer aux discussions, aux débats et même aider à évacuer les gens si jamais l'alarme incendie vient à sonner.

![](../../ressources/dessin1.png)

## Allure
Structure  d'aluminium qui se replie sur elle-même pour ne former qu'un parallélépipède rectangle qui se range facilement.


![](../../ressources/alan_structure.png)

Dans la structure sont fixés les éléments du hardware qui sont décrits dans la description technique.

## Matériaux 

Barres d'aluminium de section rectangulaire, matériel informatique.

## Description technique

### Hardware
Carte mère (avec le processeur et la carte grapique fixés dessus), refroidisseur, alimentation, boutons de façade et écran fixés dans la structure. 

### Software

[Le dépôt github de Alan](https://github.com/LeonLenclos/alan) est consacré au code source d'alan.

Les consignes d'écritures pour le développement d'Alan sont dans le fichier `brain/README.md` présent dans le dépôt github d'Alan. Cete page sert aux visiteurs et aux consignes d'installation.

L'architecture d'Alan est basé sur le module python [chatterbot](https://github.com/gunthercox/ChatterBot). Le programme d'Alan est ainsi composé de modules, des bouts de programmes qui répondent à des taches précises :
- Des modules servant à générer en fonction d'un texte entré par l'utilisateur une réponse sous forme de texte en fonction et un indice de confiance. Il sont appelés des LogicAdapter.
- Un module servant à gérer la reconnaissance vocale (conversion voix vers texte) sera un InputAdapter
- Un module servant à gérer la synthèse vocale (conversion texte vers voix) sera un OutputAdapter

Lorsque l'utilisateur dis quelque-chose à Alan, certains logic adapters se mettront en marche et c'est la réponse de celui qui renverra l'indice de confiance le plus haut qui sera sélectionnée. Si tout les logic adapters ne se mettent pas en marche à chaque fois, c'est parce que certains ne sont conçus que pour répondre à un certain type de phrases. 

### Comment parler avec Alan

Quand on lance Alan sur son harware, on arrive sur un terminal, il faut alors maintenir les touches Alt+F2 appuyés simultanément puis entrer les commandes suivantes :

  ```  
  $ gnome-terminal
  $ ./screen-setup.sh
  $ alan
  ```
Vous pouvez également  installer le programme de Alan sur votre ordinateur.

**Version de python requise : Python 3.5**

Le projet est encore en cours de développement, github est un outil adapté à ce contexte : il existe plusieurs "branches" qui sont des versions plus ou moins avancées d'Alan. Le Alan contenu dans la branche `master` doit normalement pouvoir fonctionner, il en est pour l'instant à la version 1. Il existe par exemple une branche développement sur laquelle nous travaillons et qui peut donc contenir un certain nombre de problèmes pas encores résolus. En attendant de pouvoir parler avec Alan sur internet vous pouvez suivre les indications suivantes pour installer Alan sur votre ordinateur ! Tout d'abord il vous faut télécharger ce dossier git en cliquant sur clone or download, puis rentrer les commandes suivantes dans le terminal depuis le dossier alan :

 ```
  $ pip install -r requirements.txt
  $ python
  >>> import nltk
  >>> nltk.download("punkt")
  >>> quit()
  $ cd brain
  $ ./alan.py
  ```

#### commandes spéciales

Pour quitter

```
 > ciao
```

Pour une annalyse des logic adapters en jeu dans la dernière réponse

```
 > info
```
Pour noter les deux dernières répliques dans la liste todo.md

```
 > todo
```

## Améliorations envisagées

Remplacement de l'écran et mise en ligne. Intégration et réglage du mode impro, débuggage général. Fabrication d'une housse pour pouvoir couvrir Alan. Intégration d'enceintes au hardware.

## Moment envisagé pour la construction et/ou les améliorations

Résidence au quai des savoirs du 16 au 21 novembre 2018.
