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
	quantidadeCartas = b.QuantidadeCartas();
	Mao = b;
}

void Jogador::ImprimirMao()
{
	Mao.ImprimeBaralho();
}

Carta Jogador::JogarCarta(int posicao)
{
	--quantidadeCartas;
	return Mao.RetirarCarta(posicao);
}

int Jogador::EscolherCartaParaJogar()
{
	int posicao;
	
	do
	{
		printf("\nEscolha uma carta de acordo com a posicao (1 a %d): ", QuantidadeCartasMao());
		scanf("%d", &posicao);
	}while(!Mao.EscolherCarta(posicao));
	
	return posicao;
}

int Jogador::QuantidadeCartasMao()
{
	return quantidadeCartas;
}
