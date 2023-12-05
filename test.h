


/************************************************************************/
/* linked list                                                          */
/************************************************************************/
typedef struct list_node {
    void *data;
    struct list_node *next;
} list_node;

/* linked list */
list_node* list_create(void *data);
void list_destroy(list_node **list);
list_node* list_insert_after(list_node *node, void *data);
BOOL list_remove(list_node **list, list_node *node);
list_node* list_find_node(list_node *list, list_node *node);
