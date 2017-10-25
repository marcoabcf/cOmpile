#ifndef _LEXICAL_ANALIZER_H_
#define _LEXICAL_ANALIZER_H_

typedef struct Analizer {
	void (*execute)(struct UtilLine *line)
} analizer;

analizer* Analizer();

#endif

