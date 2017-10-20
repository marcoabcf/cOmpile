#ifndef LINE_H__
#define LINE_H__
 
typedef struct UtilLine {
	char texto[100];
	int number_line;
	struct UtilLine* next;
	struct UtilLine* previous;
} utilLine;
 
//instatiate a new person
utilLine* UtilLine();
 
#endif
