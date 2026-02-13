#ifndef ALBUM
#define ALBUM
#include <iostream>

struct album {
	std::string nome, genero;
	int ano, num_musicas;
	char sera_salvo = 'N';
};

int MAX = 10; // Tamanho atual do vetor
int num_alb = 0; // NUMERO DE ALBUMS SALVOS abreviado  <- este valor é modificado pela funçao registra_album e pela leitura de dados do main.cpp
int albs_deletados = 0; //Variavel criada para a funçao imprime_albums() exibir corretamente a quantidade de albuns mesmo apos albuns serem deletados
album* colecao = new album[MAX];

// Quando o numero de elementos do vetor chegar ao tamanho maximo, o vetor ira aumentar a capacidade em 10
void aumenta_colecao(album* &colecao, int &MAX, int num_alb) {
	if (num_alb == MAX) {
		MAX+=10;
		album* nova_colecao = new album[MAX];
		for (int i = 0; i < num_alb; i++) {
			nova_colecao[i].nome = colecao[i].nome;
			nova_colecao[i].genero = colecao[i].genero;
			nova_colecao[i].ano = colecao[i].ano;
			nova_colecao[i].num_musicas = colecao[i].num_musicas;
			nova_colecao[i].sera_salvo = colecao[i].sera_salvo;
		}
		delete[] colecao;
		colecao = nova_colecao;
	}
}

#endif