#ifndef MENUS
#define MENUS
#include <iostream>
#include "register_tools.h"
#include "album.h"
using std::cout;
using std::cin;

void menu_inicial() {
	cout << "\n";
	cout << "==============================================================\n";
	cout << R"(
        _ _                                                       
       | | |                                                      
   __ _| | |__  _   _ _ __ ___   __ _ _ __   __ _  __ _  ___ _ __ 
  / _` | | '_ \| | | | '_ ` _ \ / _` | '_ \ / _` |/ _` |/ _ \ '__|
 | (_| | | |_) | |_| | | | | | | (_| | | | | (_| | (_| |  __/ |   
  \__,_|_|_.__/ \__,_|_| |_| |_|\__,_|_| |_|\__,_|\__, |\___|_|   
                                                   __/ |          
                                                  |___/                   
)" << "\n";
	cout << "==============================================================\n\n";
	cout << " << ------------ Selecione uma opcao ------------ >\n\n\t";
	cout << "[1] - Ver todos os albuns\n\t";
	cout << "[2] - Adicionar um album\n\t";
	cout << "[3] - Editar um album\n\t";
	cout << "[4] - Pesquisar um album\n\t";
	cout << "[5] - Pesquisa por genero\n\t";
	cout << "[6] - Pesquisa por posicao\n\t";
	cout << "[0] - Sair\n";
}

void pausa() {
	char tecla;
	cout << "\npressione 1 para continuar\n";
	cin >> tecla;
}

#endif
