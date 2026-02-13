#ifndef REGISTER_TOOLS
#define REGISTER_TOOLS
#include <iostream>
#include <fstream>
#include "album.h"
#include "menus.h"
using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;

void imprime(album colecao) {
		cout << "\n";
		cout << "Nome: " << colecao.nome << "\n";
		cout << "Genero: " << colecao.genero << "\n";
		cout << "Ano de lancamento: " << colecao.ano << "\n";
		cout << "Numero de musicas: " << colecao.num_musicas;
		cout << "\n";	
}

void salva_no_arquivo(album colecao[], int num_alb) {
	ofstream dados;
	dados.open("data.txt");
	for (int i = 0; i < num_alb; i++) {
		if (colecao[i].sera_salvo != 'N') {
			dados << colecao[i].nome << "\n";
			dados << colecao[i].genero << " ";
			dados << colecao[i].ano << " ";
			dados << colecao[i].num_musicas;
			dados << "\n";
		}
	}
}

void registra_album(album colecao[], int &num_alb) {
	cin.ignore();
	int i = num_alb;
	cout << "digite o nome do album: \n";
	getline(cin, colecao[i].nome);
	cout << "digite o genero do album (SEM ESPACOS POR ENQUANTO): \n";
	cin >> colecao[i].genero;
	cout << "digite o ano do album: \n";
	cin >> colecao[i].ano;
	cout << "digite quantas musicas o album possue: \n";
	cin >> colecao[i].num_musicas;
	cout << "deseja salvar as alteracoes? \n";
	cout << "[s]/[n]\n";
	char opcao;
	cin >> opcao;
	if (opcao == 's') {
		colecao[i].sera_salvo = 'S';
		num_alb++;
		salva_no_arquivo(colecao, num_alb);
	}
}

void pesquisa_album(album colecao[], int num_alb) {
	cin.ignore();
	string nomealbum;
	cout << "insira o nome do album\n";
	getline(cin, nomealbum);
	for (int i = 0; i < num_alb; i++) {
		if (nomealbum == colecao[i].nome)
			imprime(colecao[i]); 
	}
}

void imprime_albums(album colecao[], int num_alb) {
	cout << "==========================\n";
	cout << "albums totais inseridos: " << num_alb << "\n";
	for (int i = 0; i < num_alb; i++) {
		if (colecao[i].sera_salvo == 'S')
			imprime(colecao[i]);
	}
}

void edita_album(album colecao[], int num_alb) {
	// variaveis temporarias 
	string temp_nome, temp_genero;
	int temp_ano, temp_num_musicas;
	
	cin.ignore();
	string nomealbum;
	char opcaoedita, opcaosalva;
	cout << "digite o nome do album que deseja editar: \n";
	getline(cin, nomealbum);
	for (int i = 0; i < num_alb; i++) {
		if (nomealbum == colecao[i].nome) {
			imprime(colecao[i]);
			cout << "digite a acao desejada: \n";
			cout << "[1] para deletar o album\n";
			cout << "[2] para editar o album\n";
			cin >> opcaoedita;
				if (opcaoedita == '1') {
					cout << "deseja salvar as alteracoes? \n";
					cout << "[s]/[n]\n";
					cin >> opcaosalva;
					if (opcaosalva == 's') {
						colecao[i].sera_salvo = 'N';
						salva_no_arquivo(colecao, num_alb);
					}
				}
				else if (opcaoedita == '2') {
					cin.ignore();
					cout << "digite o novo nome do album: \n";
					getline(cin, temp_nome);
					cout << "digite o novo genero do album (SEM ESPACOS POR ENQUANTO): \n";
					cin >> temp_genero;
					cout << "digite o novo ano do album: \n";
					cin >> temp_ano;
					cout << "digite o novo numero de musicas: \n";
					cin >> temp_num_musicas;
					cout << "deseja salvar as alteracoes? \n";
					cout << "[s]/[n]\n";
					cin >> opcaosalva;
					if (opcaosalva == 's') {
						colecao[i].nome = temp_nome;
						colecao[i].genero = temp_genero;
						colecao[i].ano = temp_ano;
						colecao[i].num_musicas = temp_num_musicas;
						colecao[i].sera_salvo = 'S';
						salva_no_arquivo(colecao, num_alb);
					}
				}
				else
					cout << "opcao invalida. retornando ao menu...";
		}	
	}
}

#endif