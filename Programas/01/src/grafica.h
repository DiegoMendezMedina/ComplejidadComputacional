#define MAX_VERTICES 11
#define MAX_ARISTAS 15

/* Representación abstracta de un vértice de una gráfica*/
typedef struct Veritce{
  int item;
} vertice;

/* Representación abstracta de un vértice de una arista*/
typedef struct Arista{
  vertice* a;
  vertice* b;
} arista;

/* Representación abstracta de un vértice de una gráfica*/
typedef struct Grafica{
  int v;
  vertice* vertices;
  int a;
  arista* aristas;
} grafica;


/**
 * init_grafica: Crea la gráfica, alojamiento dínamico con
 *               aristas al azar. Para checar o modificar 
 *               el tamaño de vértices y aristas modificar los
 *               valores MAX_VERTICES y MAX_ARISTAS definidos 
 *               en este archivo.
 */
grafica init_grafica();

/**
 * existe: Nos índica si la arista tmp esta en g,
 *         n es hasta donde se busca en g->aristas
 * @return 1: si existe
 * @return 0: si no
 */
int existe(arista tmp, grafica* g, int n);

/**
 * printG: imprime la gráfica recibida.
 */
void printG(grafica* g);

/**
 * setOrigenYDestino: guarda en st[0] y st[1] el origen y el destino, respectivamente,
 *                   del camino en g. 
 */
void setOrigenYDestino(vertice* st, grafica* g);

/**
 * setSolucion: en solución se almacenan k aristas propuestas 
 *              como solución (con guessing).
 */
void setSolucion(grafica* g, arista* solucion, int k);

/** 
 * verificación: verifica en tiempo polinomial si el conjunto 
 *               de aristas es solución al problema de alcance en g.
 */
int verificacion(grafica* g, vertice* st, arista* solucion, int k);

/**
 * encontrar: nos dice si n figura como elemento de algun vértice
 *           en solución, k es el tamanio de solucion, vistos 
 *           funge como diccionario para llevar control de los vistos.
 * @return 1: si sí esta.
 * @return 0: si no.
 */
int encontrar(int n, arista* solucion, int k, int* vistos);

/**
 * freeG: elimina la memoria dínamica asignada
 */
void freeG(grafica* g);
