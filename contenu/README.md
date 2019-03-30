Contenu
-------




### Que vais-je trouver ici ?


Les textes que vous trouverez ici constituent à la fois :
-  Un socle théorique à notre réflexion sur l'intelligence artificielle.
-  Une forme alternative d'écriture du spectacle constituée d'un corpus de textes qui apparaîtront ou non dans la version finale.
-  Un moyen de proposer aux spectateurs "d'aller plus loin" ou de retrouver des références liées au spectacle,
-  Un outil de communication pour les professionnels ou les institutions qui voudraient plus de matière que ce que le [dossier de présentation](http://cienokill.fr/wp-content/uploads/2017/11/TURING-TEST.pdf) propose.



### Le contenu

<p class="github-pages-ignore">![think-exclamation](/ressources/icons/think-exclamation.png) Ce code génère un petit sommaire sur [le site](http://turing-test.cienokill.fr/contenu/). Ici ça affiche n'importe quoi...</p>


<div id="dir-indexing"></div>
<script>
  (async () => {
    const response = await fetch('https://api.github.com/repos/LeonLenclos/turing-test/contents/contenu');
    const data = await response.json();
    let htmlString = '<ul>';
    for (let file of data) {
      htmlString += `<li><a href="${file.path}">${file.name}</a></li>`;
    }
    htmlString += '</ul>';
    document.getElementById('dir-indexing').innerHTML = htmlString;
  })()
</script>
