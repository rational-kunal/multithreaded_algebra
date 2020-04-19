
struct node{
    struct expr *e;
    struct node *next;
};

struct stack{
    struct node *head;
};

struct stack* init_stack(){
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s->head = NULL;
    return s;
}

void push(struct stack *s,struct expr *e){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->e = e;
    new_node->next = NULL;
    if(s->head == NULL){
        s->head = new_node;
        return;
    }
    new_node->next = s->head;
    s->head = new_node; 
}

struct expr* pop(struct stack *s){
    struct node *temp_node = s->head;
    if(s->head == NULL) return NULL;
    struct expr *e = s->head->e;
    s->head = s->head->next;
    free(temp_node);
    return e;
}

int how_many(struct stack *s){
    struct node* n = s->head;
    int l = 0;
    while(n!=NULL) {
        n=n->next;
        l++;
    }

    return l;
}
