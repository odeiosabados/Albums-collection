#ifndef MENUS
#define MENUS
#include <iostream>
#include "register_tools.h"
#include "album.h"
using std::cout;
using std::cin;

char menu_inicial(char opcao) {
	do {
		cout << "\n";
		cout << "PLACEHOLDER / MENU ART / PLACEHOLDER\n\n";
		cout << "digite: \n";
		cout << "1 para ver todos os albums\n";
		cout << "2 para adicionar um album\n";
		cout << "3 para editar um album\n";
		cout << "4 para pesquisar um album\n";
		cout << "0 para sair\n";
		cin >> opcao;
		switch (opcao) {
			case '1':
				imprime_albums(colecao, num_alb);
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
	return opcao;
}

#endif
