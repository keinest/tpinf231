#include "tp231.h"

/* Verifie si une chaine de caractere saisie est un nombre reel */

bool veri_value_enter(char *str)
{
    int i = 0;
    int dot_count = 0;
    if(str[0] == '\0') return false;

    if(str[0] == '-' || str[0] == '+') i = 1;

    while(str[i] != '\0')
    {
        if(str[i] == '.')
        {
            dot_count++;
            if(dot_count > 1) return false;
        }
        else if(str[i] < '0' || str[i] > '9')
        {
            return false;
        }
        i++;
    }
    return true;
}

/* Verifie si une chaine de caractere est un nombre entier */

bool veri_user_enter(char *str)
{
    int i = 0;
    if(str[0] == '\0') return false;

    if(str[0] == '-' || str[0] == '+') i = 1;

    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return false;
        i++;
    }
    return true;
}

/* Convertie une chaine de caractere en nombre entier */

int convert_user_enter(char *str)
{
    return atoi(str);
}

/* Convertie une chaine de caractere en nombre reel */

float convert_value_enter(char *value)
{
    return atof(value);
}

/* Calcule et affiche la somme de deux matrices */

void sum_matrix(float **first, float **second, int lines, int cols)
{
    float **sum = matrix_alloc(lines, cols);
    if(!sum) return;

    for(int i = 0; i < lines; ++i)
    {
        for(int j = 0; j < cols; ++j)
            sum[i][j] = first[i][j] + second[i][j];
    }
    printf("\nLa somme des deux matrices est : \n\n");
    show_matrix(sum, lines, cols);
    matrix_free(sum, lines);
}

/* Calcule et affiche le produit de deux matrices */

void mult_matrix(float **first, float **second, int lines_first, int cols_first)
{
    float **mult = matrix_alloc(lines_first, cols_first);
    if (!mult) return;

    for(int i = 0; i < lines_first; ++i)
    {
        for(int j = 0; j < cols_first; ++j)
        {
            mult[i][j] = 0.0f;
            for(int k = 0; k < cols_first; ++k)
                mult[i][j] += first[i][k] * second[k][j];
        }
    }
    printf("Le produit des deux matrices est : \n");
    show_matrix(mult, lines_first, cols_first);
    matrix_free(mult, lines_first);
}

/* Effectue une recherche sequentielle dans un tableau */

void sequence_search(float *array, int length, float finder)
{
    for(int i = 0; i < length; ++i)
    {
        if(array[i] == finder)
        {
            printf("L'element %.2f est a la position %d du tableau !\n", finder,i + 1);
            return;
        }    
    }

    printf("L'element %.2f n'est pas dans le tableau !\n", finder);
}

/* Effectue la multiplication entre deux nombres entiers par addition successive */

int mult_add(int a, int b)
{
    int result = 0;
    int sign = 1;

    if(a < 0)
    {
        a *= - 1;
        sign *= - 1;
    }

    if(b < 0)
    {
        b *= - 1;
        sign *= - 1;
    }

    for(int i = 0; i < b; i++)
        result += a;

    return result * sign;
}

/* Fonction booleene pour verifier si un tableau de nombres est trie ou non */

bool test_sort_array(float *array, int length)
{
    if(length <= 1) return true;
    for(int i = 0; i < length - 1; ++i)
    {
        if(array[i] > array[i + 1])
            return false;
    }
    return true;
}

/* Determine le median d'un tableau */

void array_median(float *array, int length)
{
    if(!test_sort_array(array, length))
    {
        printf("Impossible de determiner l'element median, le tableau n'est pas trie !\n");
        return;
    }
    if(length % 2 == 1)
        printf("L'element median est %.2f\n", array[length / 2]);
    
    else
    {
        float median = (array[length / 2 - 1] + array[length / 2]) / 2.0f;
        printf("Le median est %.2f\n", median);
    }
}

/* Inverser un tableau de nombres */

void reverse_array(float *array, int length)
{
    int i = 0;
    int j = length - 1;
    while(i < j)
    {
        float temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
    printf("\nLe tableau inverse : \n\n");
    show_vector(array,length);
}

/* Recuperer le nombre de lignes et de colonnes pour une matrice */

void matrix_line_col(int *lines,int *cols)
{
    char value[100];
    printf("Entrer le nombre de lignes de votre matrice : ");
    scanf(" %99[^\n]",value);
    while(!veri_user_enter(value))
    {
        printf("Format de nombre incorrect !\n Reessayez !\n\n");
        printf("Entrer le nombre de lingnes de votre matrice : ");
        scanf(" %99[^\n]",value);
    }

    *lines = convert_user_enter(value);

    printf("Entrer le nombre de colonnes de votre matrice : ");
    scanf(" %99[^\n]",value);
    while(!veri_user_enter(value))
    {
        printf("Format de nombre incorrect !\n Reessayez !\n\n");
        printf("Entrer le nombre de colonnes de votre matrice : ");
        scanf(" %99[^\n]",value);
    }

    *cols = convert_user_enter(value);
}

/* Remplir une matrice avec ses differentes valeurs */

void fill_matrix(float **matrix, int lines, int cols)
{
    char value[100];
    for(int i = 0; i < lines; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("Entrer l'element [%d][%d] : ", i, j);
            scanf(" %99[^\n]", value);
            while(!veri_value_enter(value))
            {
                printf("Format de nombre incorrect ! Reessayez !\n");
                printf("Entrer l'element [%d][%d] : ", i, j);
                scanf(" %99[^\n]", value);
            }
            matrix[i][j] = convert_value_enter(value);
        }
    }
}

/* Recuperer le nombre de coordonnees d'un vecteur */

void vector_line(int *coord)
{
    char value[100];
    printf("Entrer le nombre d'elements de votre vecteur : ");
    scanf(" %99[^\n]",value);
    while(!veri_user_enter(value))
    {
        printf("Format de nombre incorrect !\nReessayez !\n");
        printf("Entrer le nombre d'elements de votre vecteur : ");
        scanf(" %99[^\n]",value);
    }

    *coord = convert_user_enter(value);
}

/* Remplir un vecteur avec ses differentes coordonnees */

void fill_vector(float *vector,int coord)
{
    char value[100];
    for(int i = 0; i < coord; i++)
    {
        printf("Entrer l'element [%d] : ",i);
        scanf(" %99[^\n]",value);
        while(!veri_value_enter(value))
        {
            printf("Format de nombre incorrect !\nReessayez !\n\n");
            printf("Entrer l'element [%d] : ",i);
            scanf(" %99[^\n]",value);
        }
        vector[i] = convert_value_enter(value);
    }
}

/* Calcule et affiche le resultat du produit vectoriel entre deux vecteurs */

void cross_product(float *vect1, float *vect2)
{
    float vect_prod[3];
    vect_prod[0] = vect1[1] * vect2[2] - vect1[2] * vect2[1];
    vect_prod[1] = vect1[2] * vect2[0] - vect1[0] * vect2[2];
    vect_prod[2] = vect1[0] * vect2[1] - vect1[1] * vect2[0];

    printf("\nLe produit vectoriel des deux vecteurs est : \n\n");
    show_vector(vect_prod, 3);
}

/* Calcule et affiche le resultat du produit matrice-vecteur */

void matrix_cross_product(float **matrix, int lines, int cols, float *vector)
{
    float *result_vector = (float *)malloc(lines * sizeof(float));

    if(!result_vector) 
    {
        printf("Erreur d'allocation memoire.\n");
        return;
    }

    for(int i = 0; i < lines; i++)
    {
        result_vector[i] = 0;
        for(int j = 0; j < cols; j++)
        {
            result_vector[i] += matrix[i][j] * vector[j];
        }
    }
    printf("\nLe produit matrice-vecteur est : \n\n");
    show_vector(result_vector, lines);
    free(result_vector);
}

/* Affiche les valeurs d'une matrice */

void show_matrix(float **matrix, int lines, int cols)
{
    for(int i = 0; i < lines; ++i)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%7.2f ", matrix[i][j]);
            usleep(100000);
        }
        printf("\n");
    }
    printf("\n\n");
}

/* Alloue dynamiquement de la memoire pour une matrice */

float **matrix_alloc(int lines, int cols)
{
    float **matrix = (float **)malloc(lines * sizeof(float *));
    if(!matrix) return NULL;

    for(int i = 0; i < lines; ++i)
    {
        matrix[i] = (float *)malloc(cols * sizeof(float));
        if(!matrix[i])
        {
            for(int k = 0; k < i; k++)
                free(matrix[k]);
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

/* Alloue dynamiquement de la memoire pour un vecteur */

float *vector_alloc(int elements)
{
    float *vector = (float *)malloc(elements * sizeof(float));
    
    return vector;
}

/* Libere la memoire allouee a un vecteur */

float *vector_free(float *vector)
{
    free(vector);
    return NULL;
}

/* Libere la memoire allouee a une matrice de taille nxm */

void matrix_free(float **matrix, int lines)
{
    for(int i = 0; i < lines; ++i)
        free(matrix[i]);
    free(matrix);
}

/* Affiche les valeurs d'un vecteur */

void show_vector(float *vector, int elements)
{
    printf("[ ");
    for(int i = 0; i < elements; ++i)
    {
        printf("%.2f ", vector[i]);
        usleep(90000);
    }
    printf("]\n\n");
}

/* Affichage de l'interface utilisateur */

void user_interface()
{
    system("clear");
    printf("\033[1m\t\t\t~~~~~ Mini systeme de calculs mathematiques ~~~~~\n");
    printf("\n\t\t\t\t~~~~~ Menu ~~~~~\n\n");
    printf("\t\t\t01 --> Addition matricielle\n");
    printf("\t\t\t02 --> Produit matriciel\n");
    printf("\t\t\t03 --> Recherche sequentielle\n");
    printf("\t\t\t04 --> Multiplication par addition\n");
    printf("\t\t\t05 --> Tester si un tableau est trie\n");
    printf("\t\t\t06 --> Trouver l'element median d'un tableau\n");
    printf("\t\t\t07 --> Inverser un tableau\n");
    printf("\t\t\t08 --> Produit vectoriel\n");
    printf("\t\t\t09 --> Produit matrice-vecteur\n");
    printf("\t\t\t00 --> Quitter\n");
    printf("\n\n\t\t\t\tEntrer une option : ");
}

/* Arrete l'execution du programme jusqu'a ce que l'on clique sur <Entrer> */

void stop()
{
    printf("\n\n\n\033[1m\033[31m\t\t\t\t<Entrer>\033[0m\033[1m");
    if(getchar() == '\n')
        getchar();
}