struct node {
    int i;
    struct node *next;
};

void print_list(struct node *node);
struct node * insert_front(struct node *node, int value);
struct node * free_list(struct node *node);