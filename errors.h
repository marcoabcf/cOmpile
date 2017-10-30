#ifndef _ERRORS_H_
#define _ERRORS_H_

typedef struct Errors {
    void (*print)(int type, int numberLine, char *word, int indexCharacter);
} errors;

errors* Errors();

#endif

