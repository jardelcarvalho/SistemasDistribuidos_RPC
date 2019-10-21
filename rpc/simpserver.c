#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simp.h"

int *
cria_dicionario_1_svc(void *p, struct svc_req *rqstp)
{
	int sig;

	FILE *f = fopen("dicionario.txt", "w");
	sig = fclose(f);

	return &sig;
}

int *
apaga_dicionario_1_svc(void *p, struct svc_req *rqstp)
{
	int sig;

	sig = remove("dicionario.txt");

	return &sig;
}


int *
insere_palavra_1_svc(word *w, struct svc_req *rqstp)
{
	int sig;

	FILE *f = fopen("dicionario.txt", "a");
	fprintf(f, "%s\n", w->word);
	sig = fclose(f);

	return &sig;
}

words *
lista_palavras_1_svc(void *p, struct svc_req *rqstp)
{
	words ws;
	FILE *f = fopen("dicionario.txt", "r");

	int i = 0, j = 0;
	while(!feof(f))
	{
		char c;
		fscanf(f, "%c", &c);
		printf("%c", c);
		if(c == '\n')
		{
			j = 0, i++;
			continue;
		}
		ws.idx[i].word[j++] = c;
	}
	ws.n = ++i;
	fclose(f);
	return &ws;
}
