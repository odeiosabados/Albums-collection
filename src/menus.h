#ifndef MENUS
#define MENUS
#include <iostream>
#include "register_tools.h"
#include "album.h"
using namespace std;

void menu_inicial() {
	char opcao;
	cout << "\n";
	cout << "PLACEHOLDER / MENU ART / PLACEHOLDER\n\n";
	cout << "digite: \n";
	cout << "1 para ver todos os albums\n";
	cout << "2 para adicionar um album\n";
	cout << "3 para editar um album\n";
	cout << "4 para pesquisar um album\n";
	
	do {
		cin >> opcao;
		switch (opcao) {
			case '1':
				// placeholder para funcao INSPEC
				break;
			case '2':
				registra_album(acervo, MAX, albums_inseridos);
				menu_inicial();
				break;
			case '3':
				// placeholder para a funcao EDIT
				break;
			case '4':
				// placeholder para a funcao SEARCH
				break;
			default:
				cout << "Opcao invalida";
		}
	} while (opcao != '0');
}
	
#endif
