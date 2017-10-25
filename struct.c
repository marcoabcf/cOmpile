#include <stdio.h>
#include <stdlib.h>

#include "struct.h"

//a "manual destructor"
void free_struct(obj) {
    free(obj);
    printf(" ---- Struct successfuly freed!");
}
 
//prints 
void print_struct() {
    printf("OK");
}
