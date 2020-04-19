#ifndef STDLIB_H 
#include <stdlib.h>
#endif

#define EXPR 0
#define NUM 1

struct expr{
    int what;
    struct expr *left;
    struct expr *right;
    char operation;
    long int value;
};

struct expr* new_expr(){
    struct expr *e = (struct expr *) malloc(sizeof(struct expr));
    e->left = NULL;
    e->right = NULL;
    e->what = EXPR;
    return e;
}

struct expr* new_num_expr(int value){
    struct expr *e = (struct expr *) malloc(sizeof(struct expr));
    e->left = NULL;
    e->right = NULL;
    e->value = value;
    e->what = NUM;

    return e;
}
