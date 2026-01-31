#ifndef ALBUM
#define ALBUM
#include <iostream>

struct album {
	std::string nome, genero;
	int ano, num_musicas;
	char sera_salvo = 'N';
};

const int MAX = 5; // Tamanho atual do vetor
int albums_inseridos = 0; // Quantidade de albums salvos  <- este valor é modificado pela funçao registra_album e futuramente pela funçao le_dados
album acervo[MAX];

#endif

