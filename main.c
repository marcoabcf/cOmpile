#include <stdio.h>

#include "struct.h"
#include "utilfile.h"
#include "symbolstable.h"
 
int main()
{
	FILE *arq;
	system("cls");
	
	arq = fopen("teste.txt", "r");
	
	utilFile* file = UtilFile();
	file->checkfile(arq);
	file->loadlines(arq);
	
	free_struct(file);
//	
//    //print
//    _(line1)->print();
//    _(line2)->print();
//     
//    //free
//    _(line1)->free();
//    _(line2)->free();
	
}
