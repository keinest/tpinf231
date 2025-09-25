# Système de calculs mathématiques en C

Ce dépôt contient un programme simple en C qui effectue diverses opérations mathématiques, y compris des calculs sur des matrices et des vecteurs. Ce projet a été une excellente occasion pour moi de m'exercer à l'allocation de mémoire dynamique, à la validation des entrées utilisateur et à l'organisation du code en C.

---

### Fonctionnalités clés

* **Opérations matricielles** : Addition et multiplication de matrices.
* **Opérations vectorielles** : Calcul du produit vectoriel de deux vecteurs et du produit d'une matrice par un vecteur.
* **Utilitaires de tableau/vecteur** : Trouver la médiane d'un tableau, vérifier si un tableau est trié, inverser un tableau et effectuer une recherche séquentielle d'un élément.
* **Arithmétique** : Multiplication de deux entiers par additions successives.

---

###  Mes contributions

Je me suis concentré sur :

* **Recherche séquentielle** : J'ai mis en œuvre la fonction `sequence_search`, qui parcourt un tableau de manière
* séquentielle pour trouver un élément donné. Cette fonction est un algorithme de recherche simple mais puissant,
* parfait pour des tableaux non triés. Elle informe l'utilisateur si l'élément a été trouvé et à quelle position,
* ou s'il n'est pas présent dans le tableau.
---

### Comment compiler et exécuter

Pour compiler le programme, vous aurez besoin d'un compilateur C comme GCC.

1.  Ouvrez votre terminal.
2.  Naviguez jusqu'au répertoire du projet.
3.  Exécutez la commande suivante pour compiler le programme :
    ```bash
    gcc main.c tp231.c -o math_program
    ```
4.  Exécutez le programme avec cette commande :
    ```bash
    ./math_program
    ```
