# **23U2793 NGNOMBOUEPO PEDEDZOUE KEINEST**


# Système de calculs mathématiques en C

Ce dépôt contient un programme simple en C qui effectue diverses opérations mathématiques, y compris des calculs sur des matrices et des vecteurs. Ce projet a été une excellente occasion pour moi de m'exercer à l'allocation de mémoire dynamique, à la validation des entrées utilisateur et à l'organisation du code en C.

---

###  Fonctionnalités clés

* **Opérations matricielles** : Addition et multiplication de matrices.
* **Opérations vectorielles** : Calcul du produit vectoriel de deux vecteurs et du produit d'une matrice par un vecteur.
* **Utilitaires de tableau/vecteur** : Trouver la médiane d'un tableau, vérifier si un tableau est trié, inverser un tableau et effectuer une recherche séquentielle d'un élément.
* **Arithmétique** : Multiplication de deux entiers par additions successives.

---

###  Mes contributions

Je me suis concentré sur la création des composants fondamentaux du programme, afin de garantir sa robustesse et sa facilité d'utilisation. Mes contributions spécifiques comprennent :

* **Gestion des entrées utilisateur** : J'ai développé toutes les fonctions de gestion des entrées utilisateur, y compris la validation des nombres entiers (`veri_user_enter`) et des nombres à virgule flottante (`veri_value_enter`). Cela empêche les plantages et garantit que le programme ne traite que des données valides.
* **Organisation du projet** : J'ai structuré le projet en plusieurs fichiers (`main.c`, `tp231.c` et `tp231.h`) afin d'améliorer la lisibilité et la maintenance du code.
* **Conversion des données** : J'ai créé les fonctions pour convertir en toute sécurité les chaînes de caractères saisies par l'utilisateur en types de données corrects (`convert_user_enter` et `convert_value_enter`).
* **Manipulation de tableau** : J'ai mis en œuvre la fonction `reverse_array`, qui inverse efficacement les éléments d'un tableau unidimensionnel.
* **Gestion de la mémoire** : J'ai écrit toutes les fonctions d'allocation (`matrix_alloc`, `vector_alloc`) et de libération (`matrix_free`, `vector_free`) de la mémoire dynamique. C'est essentiel pour prévenir les fuites de mémoire et gérer les ressources efficacement, en particulier lors de l'utilisation de matrices et de vecteurs de tailles différentes.

---

###  Comment compiler et exécuter

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
