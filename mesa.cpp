#include "Mesa.h"

Mesa::Mesa()
{
	cartas = Baralho();
	LimparArrayJogadores();
}

void Mesa::Imprimir()
{
	printf("\n---------------------Mesa---------------------");
	cartas.ImprimeBaralho();
	printf("\n");
	for(int i = 0; i < cartas.QuantidadeCartas() ; i++)
	{ 
		printf("J%d  ", jogadores[i]);
	}
	printf("\n----------------------------------------------");
}

void Mesa::AdicionarCarta(Carta c, int jogador)
{
	jogadores[cartas.QuantidadeCartas()] = ++jogador;
	cartas.AdicionarCarta(c);
}

void Mesa::Limpar()
{
	cartas.ExcluirTodasCartas();
	LimparArrayJogadores();
}

int Mesa::QuantidadeCartas()
{
	return cartas.QuantidadeCartas();
}

char Mesa::GetNaipe()
{
	return cartas.QuantidadeCartas() == 0 ? ' ' : cartas.AcessarCarta(1).GetNaipe();
}

void Mesa::LimparArrayJogadores()
{
	for(int i = 0; i < MAX_JOGADORES; i++)
	{ 
		jogadores[i] = 0; 
	}
}