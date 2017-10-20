#include <stdio.h>

#include "struct.h"
#include "validation.h"
 
int main()
{
	FILE *arq;
	system("cls");
	arq = fopen("teste.txt", "rt");
	
	utilFile* file = UtilFile();
	file->checkfile(arq);
	file->loadlines(arq);
	
	free_struct(file);
	
//    //print
//    _(line1)->print();
//    _(line2)->print();
//     
//    //free
//    _(line1)->free();
//    _(line2)->free();
	
//	struct struct_class *s;
//	s->checkarq = checkarq;
//	printf("%d", s->checkarq);
//	s->checkarq();
//	printf("%d", *s);

//	fclose(arq);
//	return 0;
}
