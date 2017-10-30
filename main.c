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

    printf("\n");
	free_struct(file);
}
