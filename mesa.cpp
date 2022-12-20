#include "Mesa.h"

Mesa::Mesa()
{
	cartas = Baralho();
}

void Mesa::Imprimir()
{
	printf("\n---------------------Mesa---------------------");
	cartas.ImprimeBaralho();
	printf("\n----------------------------------------------");
}

void Mesa::AdicionarCarta(Carta c)
{
	cartas.AdicionarCarta(c);
}

void Mesa::Limpar()
{
	cartas.ExcluirTodasCartas();
}

int Mesa::QuantidadeCartas()
{
	return cartas.QuantidadeCartas();
}

char Mesa::GetNaipe()
{
	return cartas.QuantidadeCartas() == 0 ? ' ' : cartas.AcessarCarta(1).GetNaipe();
}