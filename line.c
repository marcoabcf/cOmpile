#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "line.h"
 
utilLine* UtilLine()
{
    utilLine* new = (utilLine*) malloc(sizeof(utilLine));    
    return new;
}

