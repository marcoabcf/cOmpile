#ifndef _LINE_H_
#define _LINE_H_

typedef struct LineClass {
 
    //"class" functions
    void (*getlines)(FILE *);
} line;

//instatiate a new line
line* new_line(const char*, int);
 
//pointer to the actual line in the context
line* __actual_line;
 
//sets the actual line
line* _(line* obj);

#endif
