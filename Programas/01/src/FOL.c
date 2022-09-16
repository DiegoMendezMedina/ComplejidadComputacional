#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FOL.h"

/**
 *  Implementación de métodos descritos en FOL.h
 */

cnf initFol()
{
  int i, r, aux, j, vistos[MAX_VARIABLES];
  cnf psi;
  int b;
  
  psi.n = MAX_CLAUSULAS;
  psi.clausulas = (clausula*)malloc(sizeof(clausula)*psi.n);
  

  for(i = 0; i < MAX_CLAUSULAS; i++){
    psi.clausulas[i].n = MAX_VARIABLES;    
    psi.clausulas[i].variables = (char*)malloc(sizeof(char)*MAX_VARIABLES);
    psi.clausulas[i].forma = (int*)malloc(sizeof(int)*MAX_VARIABLES);
  }

  for(i = 0; i < MAX_VARIABLES; i++)
    vistos[i] = 0;

  aux = 'q';
  for(i = 0; i < MAX_CLAUSULAS; i++)
    for(j = 0; j < MAX_VARIABLES; j++){
      psi.clausulas[i].forma[j] = -1;
      psi.clausulas[i].variables[j] = aux+j;
    }
  
  srand(time(NULL));
  aux = 'q';
  for(i = 0; i < MAX_CLAUSULAS; i++){    
    for(j = 0; j < 3;){
      r = rand() % MAX_VARIABLES;
      while(vistos[r] != 0)
	r = rand()%MAX_VARIABLES;
      j++;
      psi.clausulas[i].forma[r] = 0;
      int rt = rand();
      if(rt%2)
	psi.clausulas[i].forma[r] = 1;
    }
  }
  
  return psi;
}

void freeFOL(cnf* psi)
{
  int i, j;

  for(i = 0; i < MAX_CLAUSULAS; i++){
    free(psi->clausulas[i].variables);
    free(psi->clausulas[i].forma);    
  }
  free(psi->clausulas);
}
void printCNF(cnf psi)
{
  int i, j, not, cont;

  printf("\n\nForumula generada aleatoriamente:\n\n");
  for(i = 0; i < MAX_CLAUSULAS; i++){
    printf("\t(");
    for(j = 0, cont = 0; j < MAX_VARIABLES && cont < 3; j++){
      if(psi.clausulas[i].forma[j] != -1){
	not = 0;
	if(psi.clausulas[i].forma[j] == 0){
	  printf("not");
	  not = 1;
	}
	if(not)
	  printf("(");
	printf("%c", psi.clausulas[i].variables[j]);
	if(not)
	  printf(")");
	if(cont < 2)
	  printf(" or ");
	cont++;
      }
    }
    printf(")");
    if(i < psi.n-1)
      printf("\n\tand\n");
    else printf("\n");
  }
  printf("\n\n");
}


void setSolucion(int* modelo)
{
  int i, r;

  srand(time(NULL));
  for(i = 0; i < MAX_VARIABLES; i++){
    r = rand();
    if(r%2 == 0)
      modelo[i] = 1;
    else modelo[i] = 0;
  }
}

void printSolucion(int* modelo)
{
  int i, aux;

  printf("La solución propuesta es:\n");
  aux = 'q';
  for(i = 0; i < MAX_VARIABLES; i++){
    printf("\tI(%c) = ", aux+i);
    if(modelo[i] == 1)
      printf("true\n");
    else printf("false\n");
  }
  printf("\n\n");
}

int verificacion(int* modelo, cnf* psi)
{
  int i, j, bool_c, bool_psi;
  int aux, k;
  
  for(i = 0; i < MAX_CLAUSULAS; i++){
    bool_c = 0;
    for(j = 0; j < MAX_VARIABLES && bool_c == 0; j++){
      aux = getNum(psi->clausulas[i].variables[j]);
      if(psi->clausulas[i].forma[j] == 1 && modelo[aux] == 1)
	bool_c = 1;      
      else if(psi->clausulas[i].forma[j] == 0 && modelo[aux] == 0)
	bool_c = 1;
    }
    if(bool_c == 0)
      return -1;
  }
  return 1;
  
}

int getNum(char c)
{
  switch(c){
  case 'q':
    return 0;
  case 'r':
    return 1;
  case 's':
    return 2;
  case 't':
    return 3;
  case 'u':
    return 4;
  case 'v':
    return 5;
  case 'w':
    return 6;
  case 'x':
    return 7;
  case 'y':
    return 8;
  case 'z':
    return 9;
  }
}
