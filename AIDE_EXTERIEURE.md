# Aide exterieure et references

Ce fichier recense les liens externes deja cites dans les commentaires du `main.c` fourni. Les extraits ci-dessous montrent les elements de code associes dans ce fichier; ils sont courts et servent a en identifier l'usage. Certains ne sont pas rendu à 100% et passent par une session de bidouillage (nécessaire pour apprendre le pseudo assembleur par exemple...).

## References utilisees

| Lien | Quoi ? | Pourquoi ? |
|---|---|---|
| [Table de couleurs ANSI (Gist)](https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a) | Couleurs dans le Terminal. | Rendre les messages de succes, d'erreur et les titres plus faciles a distinguer dans le terminal. |
| [Repeat a string - C (Rosetta Code)](https://rosettacode.org/wiki/Repeat_a_string#C) | Répéter un caractère n fois. | Certaines "box" ont des textes centrés et necessite de calculer leur position. |
| [Finding the length of an integer (Stack Overflow)](https://stackoverflow.com/questions/3068397/finding-the-length-of-an-integer-in-c) | Calculer le nombre de répétition nécessaire. | Calcule le nombre nécessaire pour le lien précédent. |
| [How would i go back to a specific line (Reddit)](https://www.reddit.com/r/Cplusplus/comments/7bdvkf/how_would_i_go_back_to_a_specific_line_in_the/?tl=fr) | Retourner à une ligne spécifique sans condition étrange. | Traduction du jump en c. |

## Extraits associes

### Couleurs du terminal

```c
#define GRN "\033[0;32m"
#define RED "\033[0;31m"
#define CRESET "\033[0m"
```

La sequence ANSI choisit une couleur; la sequence de remise a zero evite que cette couleur ne deborde sur le texte suivant.

### Repetition d'un caractere

```c
memset(buffer, caractere, longueur);
buffer[longueur] = '\0';
```

Le tampon est rempli avec le caractere demande puis termine comme une chaine C.

### Longueur affichee d'un entier positif

```c
int longueur = (int)log10(valeur) + 1;
```

Cette formule compte les chiffres d'un entier `valeur` strictement positif; `main.c` traite separement le cas zero avant de l'utiliser dû au fait que `log10(0)` n'existe pas.

### Traduction du jump en C

```c
goto menu_principal;
```

Cela permet de revenir a une ligne sans avoir a re-ecrire tout le code precedent et de garder le code lisible.

## Assignation de variable sous condition
Dans le programme, j'utilise des assignations de variables sous condition pour simplifier le code. Je n'ai pas trouvé cela depuis une source externe, dans le cours, ou par IA.
C'est une technique que j'ai decouverte en apprenant le language JavaScript, qui me semble très similaire au C dans sa structure et sa syntaxe. Cela consiste à assigner une valeur à une variable en fonction d'une condition, ce qui permet de réduire le nombre de lignes de code et d'améliorer la lisibilité. Par exemple, au lieu d'écrire :

```c
if (condition) {
    variable = valeur1;
} else {
    variable = valeur2;
}
```

On peut écrire :

```c
variable = condition ? valeur1 : valeur2;
```