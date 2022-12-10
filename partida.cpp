using namespace std;
#include <cstddef> 
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

	int posicaoCarta = 0;
	
	while(true)
	{
		system("cls");
		printf("\n**********Rodada %d**********", partidaBurro.GetRodadas());
		mesa.Imprimir();
		printf("\nVez do Jogador %d", partidaBurro.GetNumeroJogadorAtual() +  1);
		printf("\nSuas cartas:");
		jogadores[partidaBurro.GetNumeroJogadorAtual()].ImprimirMao();
		posicaoCarta = jogadores[partidaBurro.GetNumeroJogadorAtual()].EscolherCartaParaJogar();
		Carta c = jogadores[partidaBurro.GetNumeroJogadorAtual()].JogarCarta(posicaoCarta);
		mesa.AdicionarCarta(c);
		
#ifdef LOG_PROGRAM
		printf("\nCarta escolhida pelo jogador: ");
		c.ImprimeCarta();
		printf("\nQuantidade de cartas: %d", jogadores[partidaBurro.GetNumeroJogadorAtual()].QuantidadeCartasMao());
		printf("\nMao do jogador apos a rodada: ");
		jogadores[partidaBurro.GetNumeroJogadorAtual()].ImprimirMao();
		printf("\n");
		system("pause");
#endif
		partidaBurro.MudaJogadorAtual();
		//break;
	}
	return 0;
}

int NumeroProximoJogador(int numeroJogadorAtual, int quantidadeJogadores)
{
	return numeroJogadorAtual == quantidadeJogadores ? 1 : ++numeroJogadorAtual;
}