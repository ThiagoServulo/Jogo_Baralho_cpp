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
	printf("\nSuas cartas:");
	Mao.ImprimeBaralho();
}

Carta Jogador::JogarCarta(int posicao)
{
	--quantidadeCartas;
	return Mao.RetirarCarta(posicao);
}

int Jogador::EscolherCartaParaJogar(char naipeMesa)
{
	int posicao;
	
#ifdef DEBUG_Jogador_EscolherCartaParaJogar
	printf("\nNaipe da carta na mesa: %c", naipeMesa);
#endif
	
	do
	{
		printf("\nEscolha uma carta de acordo com a posicao (1 a %d) e o naipe da carta ja jogada: ", QuantidadeCartasMao());
		scanf("%d", &posicao);
	}while(!Mao.EscolherCarta(posicao) || (Mao.AcessarCarta(posicao).GetNaipe() != naipeMesa && naipeMesa != ' '));
	
	return posicao;
}

int Jogador::QuantidadeCartasMao()
{
	return quantidadeCartas;
}

bool Jogador::CartaDisponivel(char naipeMesa)
{
	if(naipeMesa == ' ')
	{
		return true;
	}
	
	for(int i = 1; i <= QuantidadeCartasMao(); i++)
	{
		if(Mao.AcessarCarta(i).GetNaipe() == naipeMesa)
		{
			return true;
		}
	}
	
	return false;
}

void Jogador::AdicionarCartaNaMao(Carta c)
{
	++quantidadeCartas;
	Mao.AdicionarCarta(c);
}