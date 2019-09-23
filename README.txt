Aula Prática de Sistemas Distribuídos
guidoni@ufsj.edu.br

JARDEL: comando para testar:
    rpcgen -C -a simp.x

Assunto: Sun RPC

Arquivos:
+ simp.x : interface contendo os procedimentos que podem ser chmados remotamente
+ simpclient.c : aplicação do cliente
+ simpsserver.c : aplicação do lado do servidor


Digite no terminal: rpcgen -C simp.x

- O compilador rpcgen irá criar os seguintes arquivos: simp.h, simp_clnt.c, simp_svc.c, simp_xdr.c
- O arquvio simp.h contém o cabeçalho dos procedimentos que podem ser chamados. Observe que o compilador modificou o nome do procedimento e colocou "_1" na frente. A aplicação cliente irá chamar "add_1(...)"
- O arquivo simp_clnt.c é o stub do cliente
- O arquivo simp_svc.c é o stub do servidor
- O arquivo simp_xdr.c é a conversão XDR


Compilando a aplicação do cliente:

gcc -c -Wall -DRPC_SVC_FG simpclient.c
gcc -c -Wall -DRPC_SVC_FG simp_clnt.c
gcc -c -Wall -DRPC_SVC_FG simp_xdr.c
gcc -o client simpclient.o simp_clnt.o simp_xdr.o -lnsl


Compilando a aplicação do servidor:

gcc -c -Wall -DRPC_SVC_FG simpservice.c
gcc -c -Wall -DRPC_SVC_FG simp_svc.c
gcc -o server simpserver.o simp_svc.o simp_xdr.o -lrpcsvc -lnsl


Execução:

1) Para executar, primeiro deixe o servidor esperando as chamadas: ./server
2) faça ./client localhost 10 20 ou ./client 127.0.0.1 10 20
