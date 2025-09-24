#include "tp231.h"

int main()
{
    char word[100];
    do
    {
        user_interface();
        scanf(" %99[^\n]",word);

        while(!veri_user_enter(word))
        {
            user_interface();
            printf("Format de nombre incorrect !\nReessayez! \n\n");
            user_interface();
            scanf(" %99[^\n]",word);
        }

        int choice = convert_user_enter(word);

        switch(choice)
        {
            case 1 :
            {
                system("clear");
                printf("\t\t\t~~~~~~~~ Addition matricielle ~~~~~~~~\n\n");
                int lines = 0,cols = 0,line = 0,col = 0;
                
                printf("Matrice A : \n\n");
                matrix_line_col(&lines,&cols);

                float **first = matrix_alloc(lines,cols);
                
                printf("Matrice B : \n\n");
                matrix_line_col(&line,&col);

                float **second = matrix_alloc(line,col);

                if(lines != line || cols != col)
                {
                    printf("Vos matrices doivent etre dans la meme dimension !\n\n");
                    matrix_free(first,lines);
                    matrix_free(second,line);    
                }
                else
                {
                    printf("Remplissez les matrices : \n\n");
                    printf("Remplissez la premiere matrice : \n\n");
                    fill_matrix(first,lines,cols);
                    printf("\nVotre matrice A est : \n\n");
                    show_matrix(first,lines,cols);
                    printf("Remplissez la deuxieme matrice : \n\n");
                    fill_matrix(second,line,col);
                    printf("\nVotre matrice B est : \n\n");

                    show_matrix(second,lines,cols);
                    sum_matrix(first,second,lines,cols);
                    matrix_free(first,lines);
                    matrix_free(second,line);
                }
                stop();
            }
            break;

            case 2:
            {
                system("clear");
                printf("\t\t\t~~~~~~~~ Multiplication matricielle ~~~~~~~~\n\n");
                int line_first = 0,cols_first = 0,line_second = 0,cols_second = 0;

                float **first_matrix = NULL,**second_matrix = NULL;
                printf("Matrice A : \n\n");
                matrix_line_col(&line_first,&cols_first);
                first_matrix = matrix_alloc(line_first,cols_first);

                printf("Matrice B : \n\n");
                matrix_line_col(&line_second,&cols_second);
                second_matrix = matrix_alloc(line_second,cols_second);

                if(cols_first != line_second)
                    printf("Impossible d'effectuer une multiplication avec ces deux matrices car elles ne sont pas compatibles. \nLe nombre de colonnes de la premiere matrice doit etre egal au nombre de lines de la deuxieme.\n");
                
                else
                {
                    printf("Remplissez vos matrices : \n\n");
                    printf("Matrice A : \n\n");
                    fill_matrix(first_matrix,line_first,cols_first);
                    printf("\nVotre matrice A est : \n\n");
                    show_matrix(first_matrix,line_first,cols_first);

                    printf("\nMatrice B : \n\n");
                    fill_matrix(second_matrix,line_second,cols_second);
                    printf("\nVotre matrice B est : \n\n");
                    show_matrix(second_matrix,line_second,cols_second);

                    mult_matrix(first_matrix,second_matrix,line_first,cols_first);
                }
                stop();
            }
            break;

            case 3:
            {
                system("clear");
                printf("\t\t\t~~~~~~~~ Recherche sequentielle ~~~~~~~~\n\n");
                int elements = 0,finder = 0;

                float *vector = NULL;
                printf("Recherche sequentielle \n\n");
                vector_line(&elements);

                vector = vector_alloc(elements);

                fill_vector(vector,elements);
                printf("Votre tableau est : \n\n");
                
                show_vector(vector,elements);

                printf("Entrer la valeur que vous souhaitez rechercher : ");
                scanf(" %99[^\n]",word);
                while(!veri_value_enter(word))
                {
                    printf("Format de nombre incorrect !\nReessayez !\n");
                    printf("Entrer la valeur que vous souhaitez rechercher : ");
                    scanf(" %99[^\n]",word);
                }
                finder = convert_value_enter(word);

                sequence_search(vector,elements,finder);
                vector = vector_free(vector);

                stop();
            }
            break;

            case 4:
            {
                system("clear");
                printf("\t\t\t~~~~~~~~ Multiplication(AxB) par addition successive ~~~~~~~~\n\n");
                int nbre_ = 0,_nbre = 0;
                printf("Entrer le premier nombre : ");
                scanf(" %99[^\n]",word);
                while(!veri_user_enter(word))
                {
                    printf("Format de nombre incorrect !\nReessayez !\n\n");
                    printf("Entrer le premier nombre : ");
                    scanf(" %99[^\n]",word);
                }
                nbre_ = convert_user_enter(word);

                printf("Entrer le deuxieme nombre : ");
                scanf(" %99[^\n]",word);
                while(!veri_user_enter(word))
                {
                    printf("Format de nombre incorrect !\nReessayez !\n\n");
                    printf("Entrer le deuxieme nombre : ");
                    scanf(" %99[^\n]",word);
                }
                _nbre = convert_user_enter(word);

                printf("Le produit de %d par %d est %d x %d = %d\n",nbre_,_nbre,nbre_,_nbre,mult_add(nbre_,_nbre));
                stop();
            }
            break;

            case 5:
            {
                system("clear");
                printf("\t\t\t~~~~~~~~ Verification de l'ordre croissant d'un tableau ~~~~~~~~\n\n");
                int elements = 0;
                float *array = NULL;
                vector_line(&elements);

                array = vector_alloc(elements);
                fill_vector(array,elements);

                show_vector(array,elements);
                if(!test_sort_array(array,elements))
                    printf("Le tableau n'est pas trie !\n");
                else
                    printf("Le tableau est trie !\n\n");
                
                array = vector_free(array);
                stop();
            }
            break;
            case 6:
            {
                system("clear");
                printf("\t\t\t~~~~~~~~ Calcul du median d'un tableau ~~~~~~~~\n\n");
                int elements = 0;
                float *array = NULL;
                vector_line(&elements);

                array = vector_alloc(elements);

                fill_vector(array,elements);
                printf("Votre tableau eat : \n");
                show_vector(array,elements);
                array_median(array,elements);

                array = vector_free(array);
                stop();
            }
            break;
            case 7:
            {
                system("clear");
                printf("\t\t\t~~~~~~~~ Inverser un tableau ~~~~~~~~\n\n");
                int elements = 0;
                float *array = NULL;
                vector_line(&elements);

                array = vector_alloc(elements);

                fill_vector(array,elements);
                printf("Votre tableau initial est : \n\n");
                show_vector(array,elements);

                reverse_array(array,elements);

                array = vector_free(array);
                stop();
            }
            break;
            case 8:
            {
                system("clear");
                printf("\t\t\t~~~~~~~~ Produit vectoriel ~~~~~~~~\n\n");
                float array_[3],_array[3];
                printf("Premier vecteur : \n\n");
                fill_vector(array_,3);
                show_vector(array_,3);

                printf("Deuxieme vecteur : \n\n");
                fill_vector(_array,3);
                show_vector(_array,3);

                cross_product(array_,_array);
                stop();
            }
            break;
            case 9:
            {
                system("clear");
                printf("\t\t\t~~~~~~~~ Produit matrice-vecteur ~~~~~~~~\n\n");
                int line = 0,col = 0,elements = 0;
                float **matrix = NULL,*vector = NULL;

                matrix_line_col(&line,&col);

                vector_line(&elements);

                if(line != elements)
                    printf("Impossible realiser cette operation!\nLe nombre de colonnes de la matrice doit etre egal au nombre de ligne du vecteur!\n");
                else
                {
                    matrix = matrix_alloc(line,col);
                    vector = vector_alloc(elements);

                    fill_matrix(matrix,line,col);
                    printf("\nVotre matrice est : \n\n");
                    show_matrix(matrix,line,col);

                    fill_vector(vector,elements);
                    printf("\nVotre vecteur est : \n\n");
                    show_vector(vector,elements);

                    matrix_cross_product(matrix,line,col,vector);
                }
                stop();
            }
            break;

            case 0:
                exit(EXIT_SUCCESS);
            break;
            default:
                printf("Option invalide !\n");
                stop();
        }

    }while(1);
}