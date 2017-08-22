#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "structs/structs.h"

int main()
{
	FILE *arq;
	system("cls");
	arq = fopen("teste.txt", "rt");
	
	struct struct_class *s;
//	s->checkarq = checkarq;
	printf("%d", s->checkarq);
//	s->checkarq();
//	printf("%d", *s);

	fclose(arq);
	return 0;
}
