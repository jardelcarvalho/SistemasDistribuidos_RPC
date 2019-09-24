/* RPC client for simple addition example */

#include <stdio.h>
#include "simp.h"  /* Created for us by rpcgen - has everything we need ! */

/* Wrapper function takes care of calling the RPC procedure */



struct words
lista_palavras(CLIENT *clnt)
{
    struct words result = lista_palavras_1(clnt);
  // operands ops;
  // int *result;
  //
  // /* Gather everything into a single data structure to send to the server */
  // ops.x = x;
  // ops.y = y;
  //
  // /* Call the client stub created by rpcgen */
  // result = add_1(&ops,clnt);
    return result;
}

// /* Wrapper function takes care of calling the RPC procedure */
//
// int sub( CLIENT *clnt, int x, int y) {
//   operands ops;
//   int *result;
//
//   /* Gather everything into a single data structure to send to the server */
//   ops.x = x;
//   ops.y = y;
//
//   /* Call the client stub created by rpcgen */
//   result = sub_1(&ops,clnt);
//   if (result==NULL) {
//     fprintf(stderr,"Trouble calling remote procedure\n");
//     exit(0);
//   }
//   return(*result);
// }


int main( int argc, char *argv[]) {
    CLIENT *clnt;
    if(argc != 2)
    {
        fprintf(stderr,"Só o host como parâmetro é necessário!\n");
        exit(0);
    }

    /* Create a CLIENT data structure that reference the RPC
     procedure SIMP_PROG, version SIMP_VERSION running on the
     host specified by the 1st command line arg. */

    clnt = clnt_create(argv[1], SIMP_PROG, SIMP_VERSION, "udp");

    /* Make sure the create worked */
    if(clnt == (CLIENT *) NULL)
    {
        clnt_pcreateerror(argv[1]);
        exit(1);
    }

    // /* get the 2 numbers that should be added */
    // x = atoi(argv[2]);
    // y = atoi(argv[3]);

    struct words words = lista_palavras(clnt);
    printf("%d palavras\n", words.n);
    //printf("%d - %d = %d\n",x,y, sub(clnt,x,y));
    return(0);
}
