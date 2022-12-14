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
	int jogadorMaiorCarta = 0;
	Carta maiorCarta;
	
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
		printf("\nQuantidade de cartas na mesa: %d", mesa.QuantidadeCartas());
		printf("\nMao do jogador apos a rodada: ");
		jogadores[partidaBurro.GetNumeroJogadorAtual()].ImprimirMao();
		printf("\n");
		system("pause");
#endif

		if (jogadores[partidaBurro.GetNumeroJogadorAtual()].QuantidadeCartasMao() == 0)
		{
			system("cls");
			printf("\nFim de jogo");
			printf("\nVencedor: Jogador %d", partidaBurro.GetNumeroJogadorAtual() +  1);
			break;
		}
		
		if(mesa.QuantidadeCartas() == 1)
		{
			jogadorMaiorCarta = partidaBurro.GetNumeroJogadorAtual();
			maiorCarta = c;
		}
		else
		{
			printf("\nxxxxx\n");
			c.ImprimeCarta();
			maiorCarta.ImprimeCarta();
			printf("\n");
			system("pause");
			if(!(maiorCarta > c))
			{
				printf("\nzzzzzzzz\n");
				maiorCarta = c;
				jogadorMaiorCarta = partidaBurro.GetNumeroJogadorAtual();
			}
		}
		
		if(partidaBurro.ChecaFimRodada())
		{
			mesa.Limpar();
			printf("\nO jogador %d venceu a rodada\n", jogadorMaiorCarta + 1);
			system("pause");
		}
		else
		{
			partidaBurro.MudaJogadorAtual();
		}
	
		partidaBurro.IncrementaRodada();
	}
	
	return 0;
}