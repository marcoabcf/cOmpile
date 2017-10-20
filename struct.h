#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef struct StructClass {    
    void (*free)();
    void (*print)();
} StructClass;

#endif

