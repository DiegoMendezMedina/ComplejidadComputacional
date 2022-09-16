#include <stdio.h>
#include "FOL.h"

/* programa01, 3-sat*/
int main()
{
  cnf psi;
  int modelo[MAX_VARIABLES], ver;
  
  psi = initFol();
  printCNF(psi);
  
  setSolucion(modelo);
  printSolucion(modelo);
  ver = verificacion(modelo, &psi);
  if(ver)
    printf("Sí\n");
  else printf("NO\n");

  freeFOL(&psi);
  return 0;
}
