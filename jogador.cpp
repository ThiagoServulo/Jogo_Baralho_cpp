#include "jogador.h"

Jogador::Jogador(int num)
{
	numJogador = num;
}

int Jogador::GetNumero()
{
	return numJogador;
}

void Jogador::IniciarMao(Baralho b)
{
	Mao = b;
}

void Jogador::ImprimirMao()
{
	Mao.ImprimeBaralho();
}