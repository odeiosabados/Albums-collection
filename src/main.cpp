#include <iostream>
#include <fstream>
#include "menu.h"

int main() {
	std::ifstream dados;
	dados.open("data.txt");
	if (dados.fail())
		std::ofstream dados("data.txt");
	
	return 0;
}
