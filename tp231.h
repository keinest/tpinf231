#ifndef __TP231__H__
#define __TP231__H__

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

//Fonctions utilitaires pour la gestion des entrees utilisateur

extern void user_interface(void);
extern bool veri_value_enter(char *); 
extern bool veri_user_enter(char *);
extern int convert_user_enter(char *);
extern float convert_value_enter(char *);


extern void sum_matrix(float **, float **, int lines, int cols);
extern void mult_matrix(float **, float **, int, int);
extern void sequence_search(float *, int, float);
extern int mult_add(int,int);
extern bool test_sort_array(float *,int);
extern void array_median(float *, int);
extern void reverse_array(float *, int );
extern void cross_product(float *, float *);
extern void matrix_cross_product(float **, int lines, int cols, float *);

//Fonctions pour remplir une matrice et un vecteur

extern void fill_matrix(float **, int, int);
extern void matrix_line_col(int *,int *);
extern void fill_vector(float *,int);
extern void vector_line(int *);

extern void stop();
extern float **matrix_alloc(int lines, int cols);
extern void matrix_free(float **matrix, int lines);
extern float *vector_alloc(int);
extern float *vector_free(float *);
extern void show_matrix(float **, int lines,int cols);
extern void show_vector(float *, int elements);

#endif
