using namespace std;

#include <algorithm>
#include <random>
#include <chrono>  
#include <tuple>
#include <vector>
#include <iostream>
#include "carta.cpp"
#include "baralho.cpp"
#include "jogador.cpp"


int main ()
{
	int quantJogadores;
	
	// Lendo a quantidade de jgadores
	while(true)
	{
		printf("Escolha a quantidade de jogadores (entre 2 e 4): ");
		scanf("%d", &quantJogadores);
		if(quantJogadores >= 2 && quantJogadores <= 4)
		{
			break;
		}
		system("cls");
	}
	
	vector<Jogador> jogadores;
	switch(quantJogadores)
	{
		case 4:
			jogadores.push_back(Jogador(4));
			
		case 3:
			jogadores.push_back(Jogador(3));
			
		case 2:
			jogadores.push_back(Jogador(2));
			jogadores.push_back(Jogador(1));
			break;
			
		default:
			break;
			// Lançar excessão;
	}

	Baralho bar1 = Baralho();
	bar1.Embaralhar();
	bar1.ImprimeBaralho();
	
	for (auto j = jogadores.rbegin(); j != jogadores.rend(); ++j)
	{
		printf("\n%d", j->GetNumero());
		j->IniciarMao(Baralho(bar1.Distribuir(5)));
		j->ImprimirMao();
	}


	return 0;
}