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
			dados.ignore();
		}
	}
	//
	char opcao;
	do {
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
		std::cout << "armazenamento maximo atual: " << MAX;
		opcao = menu_inicial(opcao);
	} while (opcao != '0');
	
	return 0;
}
