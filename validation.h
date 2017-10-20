#ifndef _UTILFILE_H_
#define _UTILFILE_H_

typedef struct UtilFile {
    void (*checkfile)(FILE *);
    void (*loadlines)(FILE *);
} utilFile;

//instatiate a new person
utilFile* UtilFile();

#endif

