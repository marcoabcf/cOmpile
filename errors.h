#ifndef _ERRORS_H_
#define _ERRORS_H_

typedef struct Errors {
    void (*print)(int type, int numberLine, char *word, char symbol);
} errors;

errors* Errors();

#endif

