#include <iostream>
#include <fstream>
#include "menus.h"
#include "register_tools.h"
#include "album.h"

int main() {
	// Leitura dos dados previamente salvos //
	std::ifstream dados;
	dados.open("data.txt");
	if (dados.fail())
		std::ofstream dados("data.txt"); // Cria um arquivo caso nao exista
	else {
		while (getline(dados, colecao[num_alb].nome) && dados >> colecao[num_alb].genero >> colecao[num_alb].ano >> colecao[num_alb].num_musicas) {
			colecao[num_alb].sera_salvo = 'S';
			num_alb++;
			dados.ignore();
		}
	}
	//Aplicacao roda ate ser inserido 0 para sair 
	char opcao;
	do {
		opcao = menu_inicial(opcao);
	} while (opcao != '0');
	
	return 0;
}
