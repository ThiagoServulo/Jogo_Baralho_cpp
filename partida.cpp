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


#define LOG_PROGRAM

int main ()
{
	int quantidadeJogadores;
	
	// Lendo a quantidade de jgadores
	while(true)
	{
		printf("Escolha a quantidade de jogadores (entre 2 e 4): ");
		scanf("%d", &quantidadeJogadores);
		if(quantidadeJogadores >= 2 && quantidadeJogadores <= 4)
		{
			break;
		}
		system("cls");
	}
	
	vector<Jogador> jogadores;
	switch(quantidadeJogadores)
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

	// Iniciar baralho de jogo
	Baralho bar = Baralho();
	bar.Embaralhar();
	
#ifdef LOG_PROGRAM
	bar.ImprimeBaralho();
#endif
	
	// Iniciar mao dos jogadores
	for (auto j = jogadores.rbegin(); j != jogadores.rend(); ++j)
	{
		j->IniciarMao(Baralho(bar.Distribuir(5)));
		
#ifdef LOG_PROGRAM
		printf("\nJogador: %d", j->GetNumero());
		printf("\nMao Inicial: ");
		j->ImprimirMao();
		printf("\n");
		system("pause");
#endif
	}

	int rodada = 1;
	int numeroJogadorAtual = 1;
	int posicaoCarta = 0;
	while(true)
	{
		system("cls");
		printf("\n****** Rodada %d ******", rodada);
		printf("\nVez do Jogador %d", numeroJogadorAtual);
		printf("\nSuas cartas:");
		jogadores[quantidadeJogadores - numeroJogadorAtual].ImprimirMao();
		printf("\nEscolha uma carta de acordo com a posicao (1 a %d): ", 
			jogadores[quantidadeJogadores - numeroJogadorAtual].GetMao().QuantidadeCartas());
		scanf("%d", &posicaoCarta);
		Carta c = jogadores[quantidadeJogadores - numeroJogadorAtual].JogarCarta(posicaoCarta);
		printf("\n");
		c.ImprimeCarta();
		
#ifdef LOG_PROGRAM
		printf("\nMao do jogador apos a rodada: ");
		jogadores[quantidadeJogadores - numeroJogadorAtual].ImprimirMao();
		printf("\n");
		system("pause");
#endif
		break;
	}
	return 0;
}

int NumeroProximoJogador(int numeroJogadorAtual, int quantidadeJogadores)
{
	return numeroJogadorAtual == quantidadeJogadores ? 1 : ++numeroJogadorAtual;
}