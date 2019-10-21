#include <stdio.h>
#include "simp.h"

// Words
// lista_palavras(CLIENT *clnt)
// {
//     Words *result = lista_palavras_1(clnt);
//     return *result;
// }



int main( int argc, char *argv[])
{
    CLIENT *clnt;
    if(argc != 2)
    {
        fprintf(stderr,"Só o host como parâmetro é necessário!\n");
        exit(0);
    }

    clnt = clnt_create(argv[1], DICT_PROG, DICT_VERSION, "udp");
    if(clnt == (CLIENT *) NULL)
    {
        clnt_pcreateerror(argv[1]);
        exit(1);
    }
    //printf("%d\n", *cria_dicionario_1((void *) NULL, clnt));
    //printf("%d\n", *apaga_dicionario_1((void *) NULL, clnt));
    struct word w;
    //printf("Palavra: ");
    //scanf("%s", w.word);
    //insere_palavra_1(&w, clnt);
    struct words *ws = lista_palavras_1((void *) NULL, clnt);
    if(ws == NULL) printf("deu erro");
    for(int i = 0; i < ws->n; i++)
    {
        printf("%d", ws->n);
        printf("%s\n", ws->idx[i].word);
    }
    return 0;
}
