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
		while (num_alb != MAX && getline(dados, colecao[num_alb].nome) && dados >> colecao[num_alb].genero >> colecao[num_alb].ano >> colecao[num_alb].num_musicas) {
			colecao[num_alb].sera_salvo = 'S';
			num_alb++;
			aumenta_colecao(colecao, MAX, num_alb);
			dados.ignore();
		}
	}
	
	char opcao;
	do {
		aumenta_colecao(colecao, MAX, num_alb);
		std::cout << "armazenamento maximo atual: " << MAX;
		menu_inicial();
		cin >> opcao;
		switch (opcao) {
			case '1':
				imprime_albums(colecao, num_alb);
				pausa();
				break;
			case '2':
				registra_album(colecao, num_alb);
				break;
			case '3':
				edita_album(colecao, num_alb);
				break;
			case '4':
				pesquisa_album(colecao, num_alb);
				break;
			default:
				cout << "Saindo ...";
		}
	} while (opcao != '0');
	
	return 0;
}