
long int solve(long int a, long int b, long int operation){
    switch(operation){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
    }
}


void doit(struct expr *e){
    // two threads to solve left side and right side
    pthread_t thread_left, thread_right;
    
    if(e->left->what == EXPR){
        // create pthread to solve left side
        // pass parametrs from left
        pthread_create(&thread_left, NULL, (void *) doit, (void *) e->left);
    }

    if(e->right->what == EXPR){
        // create pthread to solve right side
        // pass parametrs from right
        pthread_create(&thread_right, NULL, (void *) doit, (void *) e->right);
    }

    // now join the threads
    if(e->left->what == EXPR){
        pthread_join(thread_left, NULL);
    }

    if(e->right->what == EXPR){
        pthread_join(thread_right, NULL);
    }

    // struct expression will be numbers
    e->value = solve(e->left->value, e->right->value, e->operation);
    e->what = NUM;
}

