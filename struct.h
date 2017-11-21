#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef struct StructClass {    
    char (*getInvertedVector)(char *word);
    void (*clearAuxiliaryVector)(char array[]);
} StructClass;

#endif

