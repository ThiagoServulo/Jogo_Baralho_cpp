#include "jogador.h"

Jogador::Jogador(int num)
{
	numJogador = num;
}

int Jogador::GetNumero()
{
	return numJogador;
}

Baralho Jogador::GetMao()
{
	return Mao;
}

void Jogador::IniciarMao(Baralho b)
{
	Mao = b;
}

void Jogador::ImprimirMao()
{
	Mao.ImprimeBaralho();
}

Carta Jogador::JogarCarta(int posicao)
{
	return Mao.RetirarCarta(posicao);
}