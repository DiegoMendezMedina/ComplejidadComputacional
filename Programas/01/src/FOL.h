#include <stdlib.h>

/**
 * First Order Logic, funciones 
 * para generar un algoritmo no deterministico 
 * al problema 3-sat.
 */

#define MAX_VARIABLES 10
#define MAX_CLAUSULAS 5

/* abstracción de una clausula */
typedef struct Clausula{
  int n; //longitud de variables y forma
  char* variables;
  int* forma;
} clausula;

/* abstraccion de una foruma psi en cnf*/
typedef struct Cnf{
  int n;
  clausula* clausulas;
} cnf;


/** 
 * initFol: Crea una formula de Fol, en partícular
 *          una en la forma cnf.
 */
cnf initFol();

/**
 * freeFOL: libera espacio dínamico
 */
void freeFOL(cnf* psi);

/**
 * Imprime una formula psi de la forma cnf
 */
void printCNF(cnf psi);

/**
 * setSoluciones: Crea el modelo no-deterministico
 */
void setSolucion(int* modelo);

/**
 * printSolucion: Imprime el modelo
 */
void printSolucion(int* modelo);

/**
 * verificacion: en tiempo polinomial verifica si la solucion 
 *               propuesta es correcta o no.
 * @return 1 si es solución
 * @return 0 si no.
 */
int verificacion(int* modelo, cnf* psi);

/**
 * getNum: funcion auxiliar, mapea los char a int
 * @return i t.q modelo[i] representa la variable c.
 */
int getNum(char c);
