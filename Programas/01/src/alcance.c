#include <stdio.h>
#include <stdlib.h>
#include "grafica.h"

/* programa01, Problema de Alcance*/
int main()
{
  grafica g;
  arista *solucion = malloc(sizeof(arista)*MAX_ARISTAS);
  vertice st[2];
  int k;
  
  g = init_grafica();
  printG(&g);

  printf("\nElección de vertices s y t:\n");
  setOrigenYDestino(st, &g);
  k = 10;
  setSolucion(&g, solucion, k);

  printf("\tVertice s: %d\n\tVertice t: %d\n", st[0].item, st[1].item);

  printf("--Aristas seleccionadas con guessing:\n");
  for(int i = 0; i < k; i++)
    if(i %2 == 0)
      printf("\t(%2d, %2d)", solucion[i].a->item,solucion[i].b->item);
    else printf("\t(%2d, %2d)\n", solucion[i].a->item,solucion[i].b->item);
  
  printf("\n\nFase Verificadora:");

  if(verificacion(&g, st, solucion, k) != -1)
    printf("Sí\n");
  else printf("NO\n");

  freeG(&g);
  return 0;
}
