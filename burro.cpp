#include "burro.h"

Burro::Burro()
{
	cartas = Baralho();
	cartas.Embaralhar();
	mesa = Mesa();
	ConfiguraJogo();
	rodadas = 1;
}

Mesa Burro::GetMesa()
{
	return mesa;
}

int Burro::GetRodadas()
{
	return rodadas;
}

int Burro::GetQuantidadeJogadores()
{
	return quantidadeJogadores;
}

Baralho Burro::GetBaralho()
{
	return cartas;
}

vector<Jogador> Burro::GetJogadores()
{
	return jogadores;
}

void Burro::ConfiguraJogo()
{
	// Lendo a quantidade de jogadores
	while(true)
	{
		printf("Escolha a quantidade de jogadores (entre 2 e 4): ");
		scanf("%d", &quantidadeJogadores);
		if(quantidadeJogadores >= 2 && quantidadeJogadores <= 4)
		{
			InicializaJogadores();
			break;
		}
		system("cls");
	}
}

#define DEBUG_InicializaJogadores
void Burro::InicializaJogadores()
{
	switch(quantidadeJogadores)
	{
		case 4:
			jogadores.push_back(Jogador(4));
			
		case 3:
			jogadores.push_back(Jogador(3));
			
		case 2:
			jogadores.push_back(Jogador(2));
			jogadores.push_back(Jogador(1));
			break;
			
		default:
			break;
			// Lançar excessão;
	}
	
	reverse(jogadores.begin(), jogadores.end());
	
	// Iniciar mao dos jogadores
	for (auto j = jogadores.begin(); j != jogadores.end(); ++j)
	{
		j->IniciarMao(Baralho(cartas.Distribuir(5)));
		
#ifdef DEBUG_InicializaJogadores
		printf("\nJogador: %d", j->GetNumero());
		printf("\nMao Inicial: ");
		j->ImprimirMao();
		printf("\n");
		system("pause");
#endif
	}
}

void Burro::MudaJogadorAtual()
{
	jogadorAtual = jogadorAtual == (quantidadeJogadores - 1) ? 0 : ++jogadorAtual;
}

void Burro::SetJogadorAtual(int numeroJogador)
{
	jogadorAtual = numeroJogador;
}

void Burro::IncrementaRodada()
{
    ++rodadas;
}

bool Burro::ChecaFimRodada()
{
	return (rodadas % quantidadeJogadores) == 0;
}

bool Burro::ChecaFimJogo()
{
	return ((jogadores[jogadorAtual].QuantidadeCartasMao() == 0) || (mesa.QuantidadeCartas() == 0));
}

#define LOG_PROGRAM

void Burro::LoopPartida()
{
#ifdef LOG_PROGRAM
	cartas.ImprimeBaralho(); 
	printf("\n");
	system("pause");
#endif 

	int posicaoCarta = 0;
	int jogadorMaiorCarta = 0;
	Carta maiorCarta;
	
	while(true)
	{
		system("cls");
		printf("\n**********Rodada %d**********", rodadas);
		mesa.Imprimir();
		printf("\nVez do Jogador %d", jogadorAtual +  1);
		printf("\nSuas cartas:");
		jogadores[jogadorAtual].ImprimirMao();
		posicaoCarta = jogadores[jogadorAtual].EscolherCartaParaJogar();
		Carta c = jogadores[jogadorAtual].JogarCarta(posicaoCarta);
		mesa.AdicionarCarta(c);
		
#ifdef LOG_PROGRAM
		printf("\nCarta escolhida pelo jogador: ");
		c.ImprimeCarta();
		printf("\nQuantidade de cartas: %d", jogadores[jogadorAtual].QuantidadeCartasMao());
		printf("\nQuantidade de cartas na mesa: %d", mesa.QuantidadeCartas());
		printf("\nMao do jogador apos a rodada: ");
		jogadores[jogadorAtual].ImprimirMao();
		printf("\n");
		system("pause");
#endif

		if (ChecaFimJogo())
		{
			system("cls");
			printf("\nFim de jogo");
			printf("\nVencedor: Jogador %d", jogadorAtual +  1);
			break;
		}
		
		if(mesa.QuantidadeCartas() == 1)
		{
			jogadorMaiorCarta = jogadorAtual;
			maiorCarta = c;
		}
		else
		{
			if(c > maiorCarta)
			{
				maiorCarta = c;
				jogadorMaiorCarta = jogadorAtual;
			}
		}
		
		if(ChecaFimRodada())
		{
			mesa.Limpar();
			printf("\nO jogador %d venceu a rodada\n", jogadorMaiorCarta + 1);
			system("pause");
			SetJogadorAtual(jogadorMaiorCarta);
		}
		else
		{
			MudaJogadorAtual();
		}
	
		IncrementaRodada();
	}
}