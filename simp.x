#define VERSION_NUMBER 1

%#define foo 127

struct word
{
	char word[64];
};

struct words
{
	struct word idx[32];
	int n;
};

program DICT_PROG {
	version DICT_VERSION {
		int CRIA_DICIONARIO() = 1;
		int APAGA_DICIONARIO() = 2;
		int INSERE_PALAVRA(word) = 3;
		words LISTA_PALAVRAS() = 4;
   } = VERSION_NUMBER;
} = 0x23451111;
