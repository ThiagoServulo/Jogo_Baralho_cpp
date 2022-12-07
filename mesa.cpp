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