#ifndef _STRUCTS_H_
#define _STRUCTS_H_

struct line_class {
    void (*getlines)(FILE *);
};

struct validation_class {
    void (*checkarq)(FILE *);
};

struct struct_class {
    void (*checkarq)(void);
//	struct line_class line;
//	struct validation_class validation;
};

typedef struct struct_class STRUCT_CLASS;

typedef struct line_class LINE_CLASS;
typedef struct validation_class VALIDATION_CLASS;

#endif
