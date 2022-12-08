#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int es_conjunto(int*, int);
int approx_subsetsum(int* s, int n, int t, float epsilon);

/* P02: Implementación del algoritmo approx subset-sum */
int main()
{
  int n, *set, t, i, sol;
  float eps;
  
  printf("Introduce la longitud del conjunto: ");
  scanf("%d", &n);
  set = (int *) calloc(n, sizeof(int));

  printf("Introduce los %d números distintos (Conjunto):\n", n);
  for(i = 0; i < n; i++)
    scanf("%d", &set[i]);
  
  if(!es_conjunto(set, n)){
    printf("error: NO es conjunto\n");
    return 0;
  }

  printf("Introduce el númer objetivo t: ");
  scanf("%d", &t);

  printf("Introduce el factor de error: ");
  scanf("%f", &eps);
  if(eps >= 1 || eps <= 0){
    printf("error: epsilon tiene que estar en el rango (0,1)\n");
    return 0;
  }

  printf("\n\n---------- ");
  printf("Ejecución de Approx-SubseSum\n\n");
  printf("Conjunto: {");
  for(int i = 0; i < n-1; i++)
    printf("%d,", set[i]);
  printf("%d}\n",set[n-1]);
  printf("Entero Objetivo: %d\n", t);
  printf("Factor de error: %f\n", eps);
  printf("----------\n\n");
  
  sol = approx_subsetsum(set, n, t, eps);

  printf("\n++++++++ ");
  printf("Resultado::\n");
  printf("Conjunto: {");
  for(int i = 0; i < n-1; i++)
    printf("%d,", set[i]);
  printf("%d}\n",set[n-1]);
  printf("Entero Objetivo: %d\n", t);
  printf("Factor de error: %f\n", eps);
  printf("Solución aproximada: %d\n", sol);
  printf("++++++++\n");
  
  free(set);
  return 0;
}

/* funcion comparar para qsort */
int cmpf (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

/**
 * es_conjunto: Determina si set es en efecto un 
 *              conjunto o no.
 *
 * @param set, int*, simula un conjunto.
 * @param n, int, longitud del arreglo.
 * 
 * @return 1 si es conjunto, 0 si no.
 */
int es_conjunto(int* set, int n)
{
  int i, set_aux[n], aux;

  for(i = 0; i < n; i++)
    set_aux[i] = set[i];

  qsort(set_aux, n, sizeof(int), cmpf);
  aux = set_aux[0];
  for(i = 1; i < n-1; i++){
    if(set_aux[i] == aux)
      return 0;
    aux = set_aux[i];
  }

  return 1;
}

/**
 * approx_subsetsum: Implementation of the approx_subsetsum
 *                 descrita en el libro de cormen y amigos.
 * 
 * @param s, int*. conjunto represntado en un arrego.
 * @param n, longitud de s.
 * @param t, int entero objetivo.
 * @param epsilon, float. factor de error  propuesto para
 *                        entonctrar una solución acercada a la 
 *                        optima.
 * 
 * @return int. Solución propuesta con  factor (1+epsilon/(2n)) de la 
 *              solución optima.
 */
int approx_subsetsum(int* s, int n, int t, float epsilon)
{
  int i, sol;
  List *prev_l, *current_l, *trimed;
  
  prev_l = new_list(0);
  for(i = 0; i < n; i++){
    current_l = merge_lists(prev_l, add_elem_to_list(prev_l, s[i]));
    trimed = trim(current_l, (epsilon/(2.0*(float)n)));
    free_list(current_l);
    free_list(prev_l);
    remove_bigger(trimed, t);
    printf("\n***** Iteración #%d de Approx-SubsetSum:\n", i+1);
    print_list(trimed);
    printf("*****\n");
    prev_l = trimed;
  }
  
  sol = prev_l->tail->elem;
  free_list(trimed);
  free_list(prev_l);
  return sol;
}
