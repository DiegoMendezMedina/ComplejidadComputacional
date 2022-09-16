#include "grafica.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * grafica.c: implementación de los métodos
 *            descritos en grafica.h
 */

int existe(arista tmp, grafica* g, int n)
{
  int i, izq, der;

  for(i = 0; i < n; i++){
    izq = der = 0;
    if(tmp.a->item == g->aristas[i].a->item||
       tmp.a->item == g->aristas[i].b->item)
      izq = 1;
    if(tmp.b->item == g->aristas[i].a->item||
       tmp.b->item == g->aristas[i].b->item)
      der = 1;
    if(izq & der)
      return 1;
  }
  return 0;
}

grafica init_grafica()
{
  int i, r, o, aux, prev;
  grafica g;
  arista tmp;
  
  g.v = MAX_VERTICES;
  g.a = MAX_ARISTAS;
  g.vertices = (vertice*)(malloc(g.v*sizeof(vertice)));
  g.aristas = (arista*) malloc(g.a*sizeof(arista));
  
  for(i = 0; i < g.v; i++)
    g.vertices[i].item = i+1;

  srand(time(NULL));

  aux = 0;
  prev = g.v+1;
  while(aux < g.a){
    r = rand()%g.v;
    o = r;
    while(r == o)
      o = rand()%g.v;
    prev = o;
    tmp.a = &g.vertices[r];
    tmp.b = &g.vertices[o];
    if(!existe(tmp, &g, aux))
      g.aristas[aux++] = tmp;
  }

  return g;
}

void freeG(grafica* g){  
  free(g->vertices);
  free(g->aristas);
}

void printG(grafica* g)
{
  int i;

  printf("Hay %d vertices enumerados del 0 al %d\nY hay %d aristas.\n\n", g->v, g->v-1, g->a);
  for(i = 0; i < g->a; i++)
    printf("Arista %d: (%d, %d)\n",
	   i, g->aristas[i].a->item, g->aristas[i].b->item);
  
}


void setOrigenYDestino(vertice* st, grafica* g)
{
  int r, o;

  r = rand()%g->v;
  o = r;
  while(r == o)
    o = rand()%g->v;
  st[0] = g->vertices[r];
  st[1] = g->vertices[o];
}

void setSolucion(grafica* g, arista* solucion, int k)
{
  int i, aux, r, vistos[g->a];

  for(i = 0; i < g-> a; i++)
    vistos[i] = 0;
  
  aux = 0;
  for(i = 0; aux < k; i++){
    if(i == g->a)
      i = 0;
    r = rand()%g->v;
    if(r % 2 == 0 && vistos[i] == 0){
      solucion[aux++] = g->aristas[i];
      vistos[i] = 1;
    }
  }
}

int encontrar(int n, arista* solucion, int k, int* vistos)
{
  int i;
  
  i = 0;
  while(i < k){
    if(solucion[i].b->item != n ||
       solucion[i].a->item != n)
      if(vistos[i] == 0){
	vistos[i] = 1;
	return i;
      }
    i++;
  }

  return -1;
}

int verificacion(grafica* g, vertice* st, arista* solucion, int k)
{
  int i, s, t;
  int sig, aux, vistos[k]; // vistos: aristas vistas en solucion
    
  for(i = 0; i < k; i++)
    vistos[i] = 0;

  s = t = -1;
  for(i = 0; i < k; i++){
    if(solucion[i].a->item == st[0].item
       || solucion[i].b->item == st[0].item)
      s = 1;
    if(solucion[i].a->item == st[1].item
	    || solucion[i].b->item == st[1].item)
      t = 1;
  }
  
  if(s==-1 || t==-1)
    return -1;


  i = encontrar(st[0].item, solucion, k, vistos);
  if(solucion[i].a->item == st[0].item)
    sig = solucion[i].b->item;
  else sig = solucion[i].a->item;

  if(sig == st[1].item)
    return 1;
  
  vistos[i] = 1;
  aux = 0;
  while(aux < k){
    i = encontrar(sig, solucion, k, vistos);
    if(i != -1){
      if(solucion[i].a->item == st[0].item)
	sig = solucion[i].b->item;
      else sig = solucion[i].a->item;
      if(sig == st[1].item)
	return 1;
    }
    else return -1;
    aux++;
  }
  return -1;
}
