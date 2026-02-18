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
		while (num_alb != MAX && getline(dados, colecao[num_alb].nome) && dados >> colecao[num_alb].genero >> colecao[num_alb].ano >> colecao[num_alb].num_musicas >> colecao[num_alb].id) {
			colecao[num_alb].sera_salvo = 'S';
			num_alb++;
			aumenta_colecao(colecao, MAX, num_alb);
			dados.ignore();
		}
	}
	
	//  aplicacao roda ate ser digitado 0
	char opcao;
	do {
		aumenta_colecao(colecao, MAX, num_alb);
		menu_inicial();
		cin >> opcao;
		switch (opcao) {
			case '1':
				imprime_albums(colecao, num_alb, albs_deletados);
				pausa();
				break;
			case '2':
				registra_album(colecao, num_alb);
				break;
			case '3':
				edita_album(colecao, num_alb, albs_deletados);
				break;
			case '4':
				pesquisa_album(colecao, num_alb);
				break;
			case '5':
				pesquisa_por_genero(colecao, num_alb);
				break;
			case '6':
				pesquisa_por_posicao(colecao, num_alb);
			default:
				cout << "Saindo ...";
		}
	} while (opcao != '0');
	
	return 0;
}