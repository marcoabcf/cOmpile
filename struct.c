#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "memorymonitor.h"

//a "manual destructor"
void free_struct(obj) {
    free(obj);
}

//prints 
void print_struct(obj) {
	puts(obj);
    printf("OK");
}
