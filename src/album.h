#ifndef ALBUM
#define ALBUM
#include <iostream>

struct album {
	std::string nome, genero;
	int ano, num_musicas;
	char sera_salvo = 'N';
};

const int MAX = 10; // Capacidade maxima atual do vetor
int num_alb = 0; // NUMERO DE ALBUMS SALVOS abreviado  <- este valor é modificado pela funçao registra_album e pela leitura de dados do main.cpp
album colecao[MAX];

#endif

