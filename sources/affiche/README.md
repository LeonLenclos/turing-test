# Affiche Turing Test

### dimensions

- affiche = 400mm x 600mm
- fond perdu = 5mm
- total = 410mm x 610mm

### exporter en pdf

https://wkhtmltopdf.org/downloads.html

```
wkhtmltopdf -T 0mm -B 0mm -L 0mm -R 0mm --page-width 422mm --page-height 596mm --disable-smart-shrinking http://turing-test.cienokill.fr/sources/affiche/index.html affiche-turing-test.pdf
```
