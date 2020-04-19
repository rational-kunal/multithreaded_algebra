
#define OPEN_BRACE 2
#define CLOSE_BRACE 3
#define OPERATOR 4

int what_is(char x){
    if(x == '(') return OPEN_BRACE;
    if(x == ')') return CLOSE_BRACE;
    if('0' <= x && x <= '9') return NUM;
    return OPERATOR;
}

int get_digit(char x){
    return x-'0';
}

struct expr* convert(char *s, int l){
    int temp_num=0;
    char temp_op;
    char x;
    int what_x;
    bool is_num = false;

    struct stack *expr_stack = init_stack();
    struct expr *curr_expr;

    if(s[0]=='('){
        curr_expr = new_expr();
    }

    for(int i=1; i<l; i++){
        x = s[i];
        what_x = what_is(x);

        if(what_x == NUM){
            
            if(is_num){
                temp_num *= 10;
                temp_num += get_digit(x);
            }else{
                is_num = true;
                temp_num = get_digit(x);
            }

        }else {

            if(is_num){
                // not number char
                is_num = false;

                if(curr_expr->left == NULL){
                    curr_expr-> left = new_num_expr(temp_num);
                }else {
                    curr_expr-> right = new_num_expr(temp_num);
                }
            }

            if(what_x == OPERATOR){
                curr_expr->operation = x;
            }else if(what_x == OPEN_BRACE){
                struct expr *new_e = new_expr();
                
                if(curr_expr->left == NULL) curr_expr->left = new_e;
                else curr_expr->right = new_e;
                
                push(expr_stack, curr_expr);

                curr_expr = new_e;

            }else if(what_x == CLOSE_BRACE){
                struct expr *e = pop(expr_stack);
                if(e != NULL) {
                    curr_expr = e;
                }
            }

        }

    }

    return curr_expr;
}
