# Numero magique

Ce projet est un jeu de devinette de nombre en C.<br>
Le programme choisit secrètement un entier compris entre 1 et 100, et le joueur doit le retrouver en proposant des valeurs, avec des indices indiquant si le nombre recherché est plus grand ou plus petit. <br>
Il s'agit d'un dépôt pédagogique.

## Sommaire

- [Fonctionnalites](#fonctionnalites)
- [Pre-requis](#pre-requis)
- [Compilation et lancement](#compilation-et-lancement)
- [Depannage](#depannage)
- [Sources externes](#sources-externes)

## Fonctionnalites

- Nombre aleatoire compris entre 1 et 100.
- Indices pour proposer un nombre plus haut ou plus bas.
- Compteur d'essais et controle de la plage de propositions.
- Menus d'accueil et de fin, options et possibilite de rejouer.
- Options des versions recentes : limite de six essais, affichage de la plage restante et mode sarcastique.
- Messages en couleur dans la huitieme etape.

## Pre-requis

- Un compilateur C (GCC, Clang ou un compilateur compatible C11).
- Un terminal pour lancer le programme. Les couleurs ANSI dependent du terminal utilise.

## Installation, Compilation et lancement

Pour commencer, clonez le repository sur votre machine :

```sh
git clone "https://github.com/Clement-Poger/bnv-numero-magique"
```

Depuis la racine du depot, compilez le programme principal :

```sh
gcc main.c -o numero-magique -lm
```

Le lancement se fait generalement ainsi :

```sh
./numero-magique
```

## Depannage

- **Le compilateur ne trouve pas `main.c`** : lancez la commande depuis la racine du depot ou indiquez le bon chemin.
- **Les couleurs sont affichees sous forme de codes** : utilisez un terminal compatible ANSI ou compilez la version sans couleurs.
- **Une saisie incorrecte est refusee** : entrez un entier, sans texte supplementaire, dans la plage demandee.

## Sources externes

Les references externes deja associees au code source sont detaillees dans [AIDE_EXTERIEURE.md](./AIDE_EXTERIEURE.md), avec leur usage et une justification courte.
