/* Definition of the remote add and subtract procedure used by
   simple RPC example
   rpcgen will create a template for you that contains much of the code
   needed in this file is you give it the "-Ss" command line arg.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simp.h"

/* Here is the actual remote procedure */
/* The return value of this procedure must be a pointer to int! */
/* we declare the variable result as static so we can return a
   pointer to it */

struct words
lista_palavras_1_svc(struct svc_req *rqstp)
{
	FILE *f = fopen("dicionario.txt", 'r');
	struct words *words = malloc(sizeof(struct words));
	int i = 0;
	while(!feof(f))
	{
		fscanf("%s", words.idx[i++].word);
	}
	fclose(f);
	words.n = i;
	return *words;
}

// void
// insere_palavra_1_svc(key_value *argp, struct svc_req *rqstp)
// {
// 	char *path = "dicts/";
// 	int size = strlen(path) + strlen(key.name) + 1;
// 	char *dest = (char *) malloc(size * sizeof(char));
// 	FILE *f = fopen(sprintf(dest, "%s%s\0", path, key.name), 'w');
//
// 	fprinf();
// }
//
//
//
// int *
// sub_1_svc(operands *argp, struct svc_req *rqstp)
// {
// 	static int  result;
//
// 	printf("Got request: subtracting %d, %d\n",
// 	       argp->x, argp->y);
//
// 	result = argp->x - argp->y;
//
//
// 	return (&result);
// }
