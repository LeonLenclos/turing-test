#! /usr/bin/python3

import os

dirs = 'photos', 'icons', 'croquis', 'dessins', 'divers'
path = '/ressources/{d}/{f}'

md_gallery = ""
md_template = """
#### [{name}]({path})

![{name}]({path})

```
![{name}]({path})
```
"""

for d in dirs:
    print('create gallery for {}'.format(d))
    md_gallery = "\n# {} - galerie".format(d)
    files = os.listdir(d)
    files.sort()
    for f in files:
        if not f.endswith(".md"):
            print('\t{}'.format(f))
            md_gallery += md_template.format(
                name = f.split('.')[0],
                path = path.format(d=d,f=f) 
            )
    with open('{d}/gallery.md'.format(d=d), 'w') as file:
        file.write(md_gallery)
