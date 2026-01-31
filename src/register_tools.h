#ifndef REGISTER_TOOLS
#define REGISTER_TOOLS
#include <iostream>
#include <fstream>
#include "album.h"
#include "menus.h"

using namespace std;

void salva_no_arquivo(album acervo[], int tamanho, int albums_inseridos) {
	ofstream dados;
	dados.open("data.txt");
	for (int i = 0; i < albums_inseridos; i++) {
		if (acervo[i].nome != "SERA_APAGADO") {
			dados << acervo[i].nome << " ";
			dados << acervo[i].genero << " ";
			dados << acervo[i].ano << " ";
			dados << acervo[i].num_musicas;
			dados << "\n";
		}
	}
}

void registra_album(album acervo[], int tamanho, int &albums_inseridos) {
	cin.ignore();
	int tecla;
	int i = albums_inseridos;
	cout << "digite o nome do album: \n";
	getline(cin, acervo[i].nome);
	cout << "digite o genero do album: \n";
	cin >> acervo[i].genero;
	cout << "digite o ano do album: \n";
	cin >> acervo[i].ano;
	cout << "digite quantas musicas o album possue: \n";
	cin >> acervo[i].num_musicas;
	albums_inseridos++;
	salva_no_arquivo(acervo, tamanho, albums_inseridos);
}

#endif