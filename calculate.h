#include <string.h>
#include <pthread.h>
#include <stdbool.h>

#include "models.h"
#include "stack.h"
#include "do.h"
#include "convert.h"


long int calculate(char string_e[]){
    struct expr *e = convert(string_e, (int) strlen(string_e));
    doit(e);
    return e->value;
}