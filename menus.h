#ifndef MENUS
#define MENUS
#include <iostream>
#include "register_tools.h"
#include "album.h"
using std::cout;
using std::cin;

void menu_inicial() {
	cout << "\n";
	cout << "============================\n";
	cout << "PLACEHOLDER / MENU ART / PLACEHOLDER\n\n";
	cout << "digite: \n";
	cout << "1 para ver todos os albums\n";
	cout << "2 para adicionar um album\n";
	cout << "3 para editar um album\n";
	cout << "4 para pesquisar um album\n";
	cout << "0 para sair\n";
	cout << "============================\n";
}

void pausa() {
	char tecla;
	cout << "\npressione 1 para continuar\n";
	cin >> tecla;
}

#endif