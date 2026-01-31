#include <iostream>
#include <fstream>
#include "menus.h"
#include "register_tools.h"

int main() {
	std::ifstream dados;
	dados.open("data.txt");
	if (dados.fail())
		std::ofstream dados("data.txt");
	
	menu_inicial();
	
	return 0;
}
