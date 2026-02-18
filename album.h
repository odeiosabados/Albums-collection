#ifndef ALBUM
#define ALBUM
#include <iostream>

struct album {
	std::string nome, genero;
	int ano, num_musicas, id;
	char sera_salvo = 'N';
};

struct identificador {
	char caractere;
	int valor;
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

int cria_id (album p) {
	int t = 27, soma = 0, soma2 = 0;
	char alfabeto[t] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' '};
	
	identificador senha[t];
	for (int i = 0; i < t; i++) {
		senha[i].caractere = alfabeto[i];
		senha[i].valor = i;
	}
	
	std::string nome = p.nome;
	std::string nome2 = p.genero;
	
	for (int i = 0; i < nome.size(); i++) {
		for (int j = 0; j < t; j++) {
			if (nome[i] == senha[j].caractere)
				soma += senha[j].valor;
		}
	}
	for (int i = 0; i < nome2.size(); i++) {
		for (int j = 0; j < t; j++) {
			if (nome2[i] == senha[j].caractere)
				soma2 += senha[j].valor;
		}
	}
	
	return soma + soma2 + p.ano + p.num_musicas;
}
#endif
