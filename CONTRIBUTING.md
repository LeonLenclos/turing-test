Règles de rédaction
===================

Les regles de rédaction ne sont pas à suivre à la lettre, juste quand c'est possible pour homogénéiser le corpus.

Conventions d'écriture
----------------------

-   Un lien dans un texte doit apporter une information supplementaire ou citer une source, pas une information nécessaire a la conmpréhension du texte

Architecture du git
-------------------

-   on utilise pas d'accent ni de majuscule ni d'espace dans le nom des fichiers on favorise les tirets du milieu pour remplacer les espaces
-   on place tous les textes dans textes/ et tous les autres documents dans ressources/

Architecture des textes
----------------------
      
      Le titre (idem que le nom du fichier mais avec majuscule espace et accents)
      ========
      
      Type
      ----
      
      Le type de texte (essayer de ne pas inventer un nouveau type par texte)
      
      Résumé
      ------
      
      Un résumé (assez court pour pouvoir tenir dans le sommaire)
      
      Partie 1 (puis une ou plusieurs parties)
      --------
      
      texte.
      
      Partie 2
      --------
      
      texte.
      
      
      --- (une ligne séparitrice)
      
      Continuer la lecture : [**Autre texte**](autre-texte.md)


Uttilisation du markdown
------------------------

### On ne se prive pas de liste
    
    -    item
    -    item
    
    ou
    
    1-   item
    2-   item
    3-   item

### on ne se prive pas de citation

    
    > citation
    
    > citation
    > sur
    > plusieurs
    > lignes
    
### on ne se prive pas de liens et d'images

    images :
    ![](../ressources/fichier-image.png)

    liens :
    [texte](nom-du-fichier.md)
    [texte](http://site.internet.com)
    
    on peut aussi faire un lien vers un chapitre particulier :
    [texte](nom-du-fichier.md#nom-du-chapitre-en-minuscule-avec-des-tirets)
    
exemple de lien vers un chapitre particulier : [pure data](les-outils.html#fabien-et-pure-data) `[pure data](les-outils.html#fabien-et-pure-data))`
    
    
### rappel sur les titres

    Titre principal
    ==============
    
    ou
    
    # Titre principal
    
    
    sous-titre
    -----------
    
    ou 
    
    ## sous-titre
    
    
    ### sous-sous-titre

    
 ### les balise code
 
 Si on a du code a rentrer on peut le faire dans des balises codes. Si c'est `un tout petit bout de code` dans un texte normal on fait comme ça (accent grave) :
 
     c'est `un tout petit bout de code` dans un texte normal
 
 Pour des grosses portions de code on met quatres espaces au debut de chaque ligne.
 
 **Je propose qu'on uttilise aussi ça pour les extraits de spectacle qui sont ecrit comme une piece de théâtre** cf [ici](textes/interactions.md#le-robot-qui-a-de-la-r%C3%A9partie)
 
     texte normal
     
         Interlocuteur : Dialogues
         Autre interlocuteur : Autres dialogues
         Interlocuteur : ...


### autre

    *en italique* pour les titres d'oeuvres et autre truc a mettre en italique
    **en gras** pour les trucs tres importants
