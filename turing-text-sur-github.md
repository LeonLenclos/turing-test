Turing Test sur Github
======================

Git et Github sont des outils très puissants je pense qu'une fois qu'on les maitrisera un peu ce sera très bien pour nous. Je vous ai fait un petit tutoriel, peut etre essayez de tester ce que je vous y dit en meme temps que vous lisez. Vous trouverez facilement sur internet de la doc en anglais et en français pour creuser plus.

Dès que vous aurez lu ça tous les deux on pourra supprimer ce fichier.

Avant tout
----------

Fabien tu dois creer un compte sur [github](https://github.com/) et m'envoyer ton pseudo pour que je t'ajoute aux collaborateurs.

Donc en gros Git c'est un logiciel créé par Linus Torvalds un des créateurs de Linux. C'est un logiciel qui s'uttilise par lignes de commande. Github c'est une interface graphique pour ce logiciel + un herbergeur pour les projets.

Sur Github un projet c'est un repository (dépôt, repo) donc la on va travailler dans le repo [turing-test](https://github.com/LeonLenclos/turing-test)

Créer un fichier
----------------

sur la page du repo il y a un bouton "Create new file" on clic dessus pour creer un fichier. Je propose qu'on mette tous les textes dans le dossier "textes".

Ensuite il faut mettre le titre donc "turing-test/textes/le-nom-du-texte.md". Sans espaces avec des tirets et .md pour Markdown.

Ensuite ciquez sur "No wrap" et choisissez "Soft wrap" ça active le saut de ligne automatique.

Ensuite on rentre le texte, on peut avoir un aperçu en cliquant sur "Preview"

Ensuite vous cliquez sur "Commit new file".

Rédaction
---------

Alors d'abord je propose qu'on écrive tout en [Markdown](https://fr.wikipedia.org/wiki/Markdown) c'est un moyen très simple de faire de l'ultra simple mise en page très légèrement. En plus c'est très bien pris en charge par Github. sur le site que les gens visiteront ce sera transformé en html avec une belle mise en page.

Vous trouverez facilement les détails de comment ça s'uttilise. En attendant ce document est écrit en markdown donc ça vous donne une idée. Vous voyez des titres de premier niveau, des titres de deuxième niveau, des liens, etc. Vous remarquerez qu'on laisse une ligne vide entre chaque ellements et paragraphes.

Je vous propose qu'on définisse un standard pour les fichiers. regardez les textes que j'ai déjà rentré, si ça vous convient on fait comme ça pour tous les textes.

Modifier un fichier
-------------------

sur la page du repo on selectionne un fichier. et on clic sur le petit crayon. et on fait ses modifs.

ensuite si on est sûr de ses modifs on clic sur "Commit changes".

Commit
------

quand vous faites un commit (boutons "commit changes" ou "commit new file") vous avez des options de commit. Laisser tout par déffaut est une bonne option si on veut allez vite.

si possible et si utile on résume ce qu'on a fait dans le premier champ de texte. genre "corrections orthographiques" ou "suppression du paragraphe sur Terminator". c'est utile pour s'y retrouver dans l'historique.

Si on est pas sûr de son commit on peut creer une nouvelle branche en cochant "new branch".

Branch
------

on choisi un nom pour sa branche, dans le bouton, "commit" s'est transformé en "propose", on clic

on se retrouve sur une page un peu compliquée, une nouvelle branche a étée crée on vous propose de faire maintenant une pull request : dire aux autres : peux-ton faire que mes modifaction rejoignent la branche principale. Vous pouvez le faire maintenant, ou plus tard si vous n'avez pas fini vos modifs.

retournez sur la page principale du repo on voit au dessus des fichiers un menu déroulant "Branch:master" vous pouvez visitez la branche que vous venez de créer en cliquant la dessus.

si vous n'avez pas encore fait la pull request, il y a un bouton "compare & pull request"

retournez sur la page principale du repo on voit que l'on est depuis tout à l'heure dans l'onglet "code"

l'onglet "Pull request" permet de voir les pull request en cours. Quand on clic sur une pull request on peut la commenter pour en discuter. on peut cliquer sur "merge" pour fusioner avec la branch master. on nous proose ensuite "Delete branch" bien de le faire si on a plus besoin de la branch


Autres
------

README.md est un fichier qui est reconnu par github comme le fichier à afficher lorsqu'on arrive dans un repo (ou un dossier) sous la liste des fichier.

l'onglet "Issues" qui sers normalement a reporter des bugs dans un logiciel, peut etre un bon endroit pour des discussions entre-nous sur des trucs qui vont pas.

Si vous voulez travailler sur votre ordi plutot que sur le site apprenez a uttiliser git, c'est pas très compliqué. Vous pourrez avoir tous les fichiers sur votre ordi et faire des mise a jour, commit, pull request, etc, par de simples lignes de commandes.

