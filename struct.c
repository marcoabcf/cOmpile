#include <stdio.h>
#include <stdlib.h>

#include "struct.h"

//a "manual destructor"
void free_struct(obj)
{
    free(obj);
    puts("\n\nStruct successfuly freed!\nBye");
}
 
//prints 
void print_struct()
{
    printf("OK");
}
