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
#include "mesa.cpp"
#include "burro.cpp"


#define LOG_PROGRAM

int main ()
{
	Burro partidaBurro = Burro();
	
	// Vetor de jogadores
	vector<Jogador> jogadores = partidaBurro.GetJogadores();

	// Baralho do jogo
	Baralho bar = partidaBurro.GetBaralho();
	
	// Mesa do jogo
	Mesa mesa = partidaBurro.GetMesa();
	
#ifdef LOG_PROGRAM
	bar.ImprimeBaralho(); 
	printf("\n");
	system("pause");
#endif 

	int numeroJogadorAtual = 1;
	int posicaoCarta = 0;
	
	while(true)
	{
		system("cls");
		printf("\n**********Rodada %d**********", partidaBurro.GetRodadas());
		mesa.Imprimir();
		printf("\nVez do Jogador %d", numeroJogadorAtual);
		printf("\nSuas cartas:");
		jogadores[partidaBurro.GetRodadas() - numeroJogadorAtual].ImprimirMao();
		printf("\nEscolha uma carta de acordo com a posicao (1 a %d): ", 
			jogadores[partidaBurro.GetQuantidadeJogadores() - numeroJogadorAtual].GetMao().QuantidadeCartas());
		scanf("%d", &posicaoCarta);
		Carta c = jogadores[partidaBurro.GetQuantidadeJogadores() - numeroJogadorAtual].JogarCarta(posicaoCarta);
		mesa.AdicionarCarta(c);
		
#ifdef LOG_PROGRAM
		printf("\nCarta escolhida pelo jogador: ");
		c.ImprimeCarta();
		printf("\nMao do jogador apos a rodada: ");
		jogadores[partidaBurro.GetQuantidadeJogadores() - numeroJogadorAtual].ImprimirMao();
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