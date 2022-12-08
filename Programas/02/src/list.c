#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "list.h"

/**
 * Proper documentation in list.h
 */

List* list_alloc()
{
  List * list = (List*) malloc(sizeof(List));
  return list;
}

Node* node_alloc()
{
  Node* n = (Node*) malloc(sizeof(Node));
  return n;
}


Node* new_node(int n)
{
  Node* node = node_alloc();

  node->next = node->prev = NULL;
  node->elem = n;
  
  return node;
}

Node* new_empty_node()
{
  Node* node = node_alloc();
  node->next = node->prev = NULL;
  node->elem = 0;
  
  return node;
}

List* new_empty_list()
{
  List* l = list_alloc();
  l->head = l->tail = NULL;
  l->length = 0;

  return l;
}

List* new_list(int n)
{
  // checar si se puede cambiar por
  // insert_elem_to_list(l, n);
  Node* node = new_node(n);
  List* list = list_alloc();
  list->length = 1;
  list->head = node;
  list->tail = node;   
}

List* new_list_with_node(Node* n)
{
  List* list = list_alloc();
  list->length = 1;
  list->head = n;
  list->tail = n;
  n->prev = NULL;

  return list;
}

List* init_list(int *arr, int n)
{
  // Pendiente modificarla para
  // llamar función auxiliar y ver que funcione.
  if(n < 1)
    return NULL;
  
  int i;
  List * list;
  Node* aux, *prev, *next;

  aux = node_alloc();
  aux->elem = arr[0];
  prev = aux;
  list = new_list_with_node(aux);
  for(i = 1; i < n; i++){
    aux =  node_alloc();
    aux->elem = arr[i];
    aux->prev = prev;
    prev->next = aux;
    prev = aux;
    list->length++;
  }

  return list;
}

List* add_elem_to_list(List* l, int e)
{
  Node *aux, *n;
  List* new = new_empty_list();
  
  aux = l->head;
  while(aux != NULL){
    n = new_node(aux->elem+e);
    insert_node_to_list(new, n);
    aux = aux->next;
  }  
  return new;  
}

List* merge_lists(List* l1, List* l2)
{
  List *new;
  Node *h1, *h2, *n;
  
  new = new_empty_list();
  while(l1->head != NULL && l2->head != NULL){
    n = new_empty_node();
    h1 = l1->head;
    h2 = l2->head;
    
    if(h1->elem <= h2->elem)
      n->elem = h1->elem;
    else
      n->elem = h2->elem;

    insert_node_to_list(new, n);
    
    if(new->tail->elem == l1->head->elem)
      drop_head(l1);
    else drop_head(l2);
  }

  while(l1->head != NULL){
    n = new_node(l1->head->elem);
    insert_node_to_list(new, n);
    drop_head(l1);
  }


  while(l2->head != NULL){
    n = new_node(l2->head->elem);
    insert_node_to_list(new, n);
    drop_head(l2);
  }
    
  return new;
}

void empty_list(List* l)
{  
  while(!(is_empty(l)))
    drop_head(l);
}

Node* search_node(List* l, Node* n)
{
  Node *aux;

  aux = l->head;
  while(aux != NULL){
    if(aux->elem == n->elem)
      return aux;
    aux = aux->next;
  }

  return NULL;
}

void insert_elem_to_list(List* l, int e){
  Node *n = new_node(e);
  insert_node_to_list(l, n);
}

void insert_node_to_list(List *l, Node* n)
{
  if(l->head == NULL)
    l->head = l->tail = n;
  else{
    l->tail->next = n;
    n->prev = l->tail;
    l->tail = n;
  }
  l->length++;
}

void delete(List *l, Node  *n)
{
  Node *s, *a;

  s = search_node(l, n);  
  if(s == NULL)
    return;


  if(l->length == 1)
    l->head = l->tail = NULL;
  else if(l->head == n){
    s = n->next;
    s->prev = NULL;
    l->head = s;
  }
  else if(l->tail == n){
    a = n->prev;
    a->next = NULL;
    l->tail = a;
  }
  else{
    a = n->prev;
    s = n->next;

    a->next = s;
    s->prev = a;    
  }

  l->length--;
  free(n);
}

void drop_head(List* l)
{
  if(l->head == NULL)
    return;
  
  delete(l, l->head);
}

int is_empty(List* l)
{
  return (l->head == NULL)? 1:0;
}

void print_list(List* list)
{
  Node* aux, *change;

  printf("======== Imprimiendo Lista\nList length: %d\n", list->length);
  aux = list->head;
  while(aux != NULL){
    printf("|%d|->", aux->elem);
    change = aux->next;
    aux = change;
  }
  printf("\n========\n");
}

void free_list(List *l)
{
  Node *aux, *current;

  current = l->head;
  while(current != NULL){
    aux = current->next;
    free(current);
    current = aux;
  }
  
  free(l);
}

List* trim(List* l, float delta)
{
  int last;
  Node *aux;
  List *new_l;
  
  aux = l->head;
  new_l = new_list(aux->elem);
  last = aux->elem;
  aux = aux->next;
  while(aux != NULL){
    if(aux->elem > (int)(ceil(last*(1+delta)))){
      insert_elem_to_list(new_l, aux->elem);
      last = aux->elem;
    }
    aux = aux->next;      
  }
  return new_l;
}

void remove_bigger(List *l, int t)
{
  Node *aux, *n;

  aux = l->head;
  while(aux != NULL){
    n = aux;
    aux = aux->next;
    if(n->elem > t)
      delete(l, n);
  }
}
