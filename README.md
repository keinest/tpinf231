# tpinf231

# Mini système de calculs mathématiques

Ce projet est un programme en langage C qui offre une suite d'outils mathématiques pour la manipulation de matrices et de vecteurs, ainsi que d'autres calculs numériques. Il est conçu pour être facile à utiliser avec une interface utilisateur en console.

---

## Fonctionnalités

Le programme propose un menu principal avec les options suivantes :

* **Addition matricielle (01):** Calcule et affiche la somme de deux matrices. Les matrices doivent avoir les mêmes dimensions.
* **Produit matriciel (02):** Calcule et affiche le produit de deux matrices. Le nombre de colonnes de la première matrice doit être égal au nombre de lignes de la seconde.
* **Recherche séquentielle (03):** Recherche la position d'un élément dans un tableau.
* **Multiplication par addition (04):** Effectue la multiplication de deux nombres entiers en utilisant des additions successives.
* **Tester si un tableau est trié (05):** Vérifie si un tableau de nombres est trié par ordre croissant.
* **Trouver l'élément médian d'un tableau (06):** Détermine l'élément médian d'un tableau. Pour que cette fonction opère correctement, le tableau doit être trié.
* **Inverser un tableau (07):** Inverse l'ordre des éléments d'un tableau.
* **Produit vectoriel (08):** Calcule le produit vectoriel de deux vecteurs à 3 dimensions.
* **Produit matrice-vecteur (09):** Calcule le produit d'une matrice et d'un vecteur. Le nombre de colonnes de la matrice doit être égal au nombre d'éléments du vecteur.
* **Quitter (00):** Permet de fermer le programme.

---

## Compilation et exécution

### Prérequis

* Un compilateur C (comme GCC).

### Étapes

1.  **Enregistrez les fichiers :** Assurez-vous d'avoir les fichiers `main.c`, `tp231.c`, et `tp231.h` dans le même répertoire.

2.  **Compilez le programme :** Ouvrez votre terminal et exécutez la commande suivante :
    ```sh
    gcc main.c tp231.c -o tp231
    ```
    Cette commande compile le code source et crée un fichier exécutable nommé `tp231`.

3.  **Exécutez le programme :** Lancez le programme avec la commande :
    ```sh
    ./tp231
    ```

---

## Structure des fichiers

* `main.c`: Contient la fonction `main` et l'interface utilisateur. Il gère la logique de navigation à travers le menu et appelle les fonctions appropriées en fonction du choix de l'utilisateur.
* `tp231.c`: Contient les implémentations des fonctions mathématiques et utilitaires, telles que l'addition de matrices, le produit vectoriel, la gestion de la mémoire, et les validations de saisie.
* `tp231.h`: Le fichier d'en-tête qui déclare toutes les fonctions publiques disponibles dans le projet, ce qui permet de lier les différents fichiers source.


## Contributeurs

    .NGNOMBOUEPO PEDEDZOUE KEINEST -> 23U2793
    .IKENG HENGA FLORENT DAVID -> 22T2857
    .NGUEFAH ZEUTCHA CAROL JUNIOR -> 23U2597
    .ESSENGUE BILOA MICHEL VICTORIEN -> 
    .BIHOYA NSOH FRANCK EMMANNUEL -> 
    .TUINTCHEU LINARESSE JOBRELLE -> 24F2760
