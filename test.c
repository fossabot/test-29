/* Creates a list (node) and returns it
 * Arguments: The data the list will contain or NULL to create an empty
 * list/node
 */
list_node* list_create(void *data)
{
    list_node *l = osal_malloc(sizeof(list_node));
    if (l != NULL) {
        l->next = NULL;
        l->data = data;
    }

    return l;
}

/* Completely destroys a list
 * Arguments: A pointer to a pointer to a list
 */
void list_destroy(list_node **list)
{
    if (list == NULL) return;
    while (*list != NULL) {
        list_remove(list, *list);
    }
}

/* Creates a list node and inserts it after the specified node
 * Arguments: A node to insert after and the data the new node will contain
 */
list_node* list_insert_after(list_node *node, void *data)
{
    list_node *new_node = list_create(data);
    if (new_node) {
        new_node->next = node->next;
        node->next = new_node;
    }
    return new_node;
}

/* Removes a node from the list
 * Arguments: The list and the node that will be removed
 */
BOOL list_remove(list_node **list, list_node *node)
{
    list_node *tmp = NULL;
    if (list == NULL || *list == NULL || node == NULL) return FALSE;

    if (*list == node) {
        *list = (*list)->next;
        osal_free(node);
        node = NULL;
    } else {
        tmp = *list;
        while (tmp->next && tmp->next != node) tmp = tmp->next;
        if (tmp->next) {
            tmp->next = node->next;
            osal_free(node);
            node = NULL;
        }
    }

    if (NULL != node) {
        return FALSE;
    }
    return TRUE;
}

/* Find an element in a list by the pointer to the element
 * Arguments: A pointer to a list and a pointer to the node/element
 */
list_node* list_find_node(list_node *list, list_node *node)
{
    while (list) {
        if (list == node) break;
        list = list->next;
    }
    return list;
}
