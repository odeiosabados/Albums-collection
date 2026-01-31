#ifndef _ALBUM_
#define _ALBUM_
#include <iostream>

struct album {
	std::string nome, genero;
	int ano, num_musicas;
};

const int MAX = 2; // Tamanho atual do vetor
int albums_inseridos = 0; // Quantidade de albums salvos
album acervo[MAX];

#endif