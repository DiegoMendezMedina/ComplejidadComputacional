/* Node abstraction */
typedef struct node
{
  int elem;
  struct node* next;
  struct node* prev;
} Node;

/* List abstraction */
typedef struct list
{
  int length;
  Node* head;
  Node* tail;
} List;

/* List memory allocation */
List* list_alloc();

/* Node memory allocation */
Node* node_alloc();

/**
 * new_node: Creates node with elem e.
 *
 * @param e, int. node representation.
 * @return node with elem e, 
 *              prev and next as NULL
*/
Node* new_node(int e);

/**
 * new_empty_node: Creates and empty node, with 
 *                 prev = next = NULL, 
 *                 elem default as 0.
 * 
 * @returns Node*, new empty Node.
 */
Node* new_empty_node();
  
/**
 * new_empty_list: Creates an empty list
 *
 * @return proper empty list representation.
 */
List* new_empty_list();

/**
 * new_list: 
 */
List* new_list(int n);

/**
 * new_list_with_node: Creates a list 
 *                  head only.
 * 
 * @param n, Node*. head of new list.
 *
 * @return List*, new list.
 */
List* new_list_with_node(Node* n);
  
/**
 * init_list: creates a list with the values in
 *            arr. 
 * 
 * @param arr, int*. array with values.
 * @param n, int. length of arr.
 * 
 * @return List* representation of arr.
 */
List* init_list(int* arr, int n);

/**
 * add_elem_to_list: Cormen and friends definition of
 *                 L + x, where L is a list 
 *                 and x an integer. Copies L in L',
 *                 add x to every element in L'.
 * 
 * @param l, List*. List to copy and modify.
 * @param e, int. integer that modifies L'.
 */
List* add_elem_to_list(List* l, int e);

/**
 * merge_list: Merge two lists.
 *
 * @param l1, List*. Order list.
 * @param l2, List*, Order list.
 * 
 * @return List*, new merged List.
 */
List* merge_lists(List* l1, List* l2);

/**
 * empty_list: empties the list received.
 * 
 * @param List*, list to empty.
 */
void empty_list(List*);

/**
 * search_node: Given a node n, 
 *         checks if n->elem is in 
 *         List l.
 *
 * @param l, List*, list to search.
 * @param n, Node*, node been searched. 
 * 
 * @return Node*, node in l with same value as 
 *                n->elem. Otherwise NULL.
 */
Node* search_node(List* l, Node* n);

/**
 * insert_node_to_list: Given a node, n, 
 *                 it is insert at the end of 
 *                 the list received.
 *
 * @param List*, list to insert node.
 * @param Node*, node to insert.
 */
void insert_node_to_list(List*, Node*);

/** 
 * insert_elem_to_list: Given an integer n,
 *                  it creates a node and 
 *                  inserts it at the end of the 
 *                  list received.
 *
 * @param List*, list to insert.
 * @param int, elem to create new node. 
 */
void insert_elem_to_list(List*, int);

/**
 * delete: Deletes node n in l,
 *         checks if it is in l.
 *
 * @param l, List*. List to delete node.
 * @param n, Node*. Node to delete.
 */
void delete(List *l, Node  *n);

/**
 * drop_head: deletes the head of the 
 *          list received.
 *
 * @param l, List*. List that the head 
 *                will be deleted.
 */
void drop_head(List* l);


/**
 * is_empty: Tells if the list received 
 *           is empty or not.
 *
 * @param List*. List to check.
 *
 * @return 1 if it's empty, otherwhise 0.
 */
int is_empty(List*);
/**
 * print_list: prints in EO the representation
 *             of the list received.
 *
 * @param list, List*. List to print.
 */
void print_list(List* list);

/**
 * free_list: frees the memory of all the nodes
 *            in the list and itself.
 * 
 * @param List*. List to be free.
 */
void free_list(List*);

/**
 * trim: following cormen and friends definition, 
 *       numbers can have representation according 
 *       to the delta factor, this function achieves 
 *       this.
 *
 * @param l, List. list to trim.
 * @param deltfa, float. factor to represent numbers.
 *
 * @return delta, List. new list trimed.
 */
List* trim(List* l, float delta);

/**
 * remove_bigger: remove every element in 
 *                the list received that is bigger 
 *                than t;
 * Nota* Estaba pensando que a lo mejor esta función
 *       podria regresar un entero, regresar INT_MIN
 *       si no se encontro t en la lista y t si 
 *      si se encontro, finalizando así las iteraciones 
 *      de approx_subsetsum.
 *
 * @param l, List. list to iterate.
 * @param t, int. Number
 */
void remove_bigger(List *l, int t);
