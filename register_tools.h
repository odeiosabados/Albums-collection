#ifndef REGISTER_TOOLS
#define REGISTER_TOOLS
#include <iostream>
#include <fstream>
#include "album.h"
using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;

void imprime(album colecao) {
	cout << "\n";
	cout << "ID " << colecao.id << "\n";
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
			dados << colecao[i].num_musicas << " ";
			dados << colecao[i].id;
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
	cout << "digite quantas musicas o album possui: \n";
	cin >> colecao[i].num_musicas;
	cout << "deseja salvar as alteracoes? \n";
	cout << "[s]/[n]\n";
	char opcao;
	cin >> opcao;
	if (opcao == 's') {
		colecao[i].sera_salvo = 'S';
		colecao[i].id = cria_id(colecao[i]);
		num_alb++;
		salva_no_arquivo(colecao, num_alb);
	}
}

void pesquisa_album(album colecao[], int num_alb) {
	cout << "==============================================================\n";
	cout << R"(                                                                                 
              ##################                  
            ######          ######                
            ####              ####                
          ######                ####              
          ####                  ####              
          ####                  ####              
            ####              ####                
            ####              ####                
            ######          ######                
              ##################                  
                  ##############                  
                            ######                
                              ######              
                                ####                                                                                                               
)" << "\n";
	cout << "==============================================================\n\n";
	cin.ignore();
	bool encontrou = false;
	string nomealbum;
	cout << "Insira o nome do album: \n";
	getline(cin, nomealbum);
	for (int i = 0; i < num_alb; i++) {
		if (nomealbum == colecao[i].nome && colecao[i].sera_salvo == 'S') {
			imprime(colecao[i]);
			encontrou = true;
		}
	}
	if (!encontrou)
		cout << "Nenhum album encontrado com esse nome";
}

void imprime_albums(album colecao[], int num_alb, int albs_deletados) {
	cout << "==========================\n";
	cout << "Albuns totais inseridos: " << num_alb - albs_deletados << "\n";
	for (int i = 0; i < num_alb; i++) {
		if (colecao[i].sera_salvo == 'S')
			imprime(colecao[i]);
	}
}

void pesquisa_por_genero(album colecao[], int num_alb) {
	cout << "==============================================================\n";
	cout << R"(                                                        
              ##################                  
            ######          ######                
            ####              ####                
          ######                ####              
          ####                  ####              
          ####                  ####              
            ####              ####                
            ####              ####                
            ######          ######                
              ##################                  
                  ##############                  
                            ######                
                              ######              
                                ####              
                                ######                                                                                     
)" << "\n";
	cout << "==============================================================\n\n";
	cin.ignore();
  string genero_buscado;
  bool encontrou = false;
  cout << "Digite o genero que deseja buscar: ";
  getline(cin, genero_buscado);
  cout << "\n=== Albuns do genero: " << genero_buscado << " ===\n";
  for (int i = 0; i < num_alb; i++) {
		if (genero_buscado == colecao[i].genero && colecao[i].sera_salvo == 'S') {
      imprime(colecao[i]);
      encontrou = true;
    }
  }
	if (!encontrou) {
		cout << "Nenhum album encontrado para esse genero.\n";
  }
  cout << "==========================================\n";
}

void pesquisa_por_posicao(album colecao[], int num_alb) {
	cout << "==============================================================\n";
	cout << R"(                                             
              ##################                  
            ######          ######                
            ####              ####                
          ######                ####              
          ####                  ####              
          ####                  ####              
            ####              ####                
            ####              ####                
            ######          ######                
              ##################                  
                  ##############                  
                            ######                
                              ######              
                                ####              
                                ######                                                                                          
)" << "\n";
	cout << "==============================================================\n\n";
  int inicio, fim;
  bool encontrou = false;
  cout << "=== Mostrar Albuns por Posicao ===\n";
  cout << "Mostrar a partir do album numero: ";
  cin >> inicio;
  cout << "Ate o album numero: ";
  cin >> fim;
  int var_inicio = inicio - 1;
  int var_fim = fim - 1;
  cout << "\n--- Exibindo do " << inicio << " ao " << fim << " ---\n";
  for (int i = var_inicio; i <= var_fim; i++) {
  	if (i >= 0 && i < num_alb) {
      if (colecao[i].sera_salvo == 'S') {
        cout << "Posicao [" << i + 1 << "]:";
        imprime(colecao[i]);
        encontrou = true;
      }
    }
	}
  if (!encontrou) {
    cout << "Nenhum album encontrado nesse intervalo de posicoes.\n";
  }
  cout << "----------------------------------\n";
}

void edita_album(album colecao[], int num_alb, int &albs_deletados) {
	// variaveis temporarias 
	string temp_nome, temp_genero;
	int temp_ano, temp_num_musicas;
	
	cin.ignore();
	string nomealbum;
	char opcaoedita, opcaosalva;
	cout << "digite o nome do album que deseja editar: \n";
	getline(cin, nomealbum);
	for (int i = 0; i < num_alb; i++) {
		if (nomealbum == colecao[i].nome && colecao[i].sera_salvo == 'S') {
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
						albs_deletados++;
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
