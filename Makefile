all:
	gcc -c -Wall -DRPC_SVC_FG simpclient.c
	gcc -c -Wall -DRPC_SVC_FG simp_clnt.c
	gcc -c -Wall -DRPC_SVC_FG simp_xdr.c
	gcc -o client simpclient.o simp_clnt.o simp_xdr.o -lnsl
	gcc -c -Wall -DRPC_SVC_FG simpserver.c
	gcc -c -Wall -DRPC_SVC_FG simp_svc.c
	gcc -o server simpserver.o simp_svc.o simp_xdr.o -lrpcsvc -lnsl
