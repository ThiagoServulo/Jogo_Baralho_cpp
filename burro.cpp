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
	while(true)
	{
		// Lendo a quantidade de jogadores
		printf("Escolha a quantidade de jogadores (entre 2 e 4): ");
		scanf("%d", &quantidadeJogadores);
		if(quantidadeJogadores >= 2 && quantidadeJogadores <= 4)
		{
			InicializaJogadores();
			break;
		}
		LimparTerminal();
	}
}

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
		
#ifdef DEBUG_Burro_InicializaJogadores
		printf("\nJogador: %d", j->GetNumero());
		printf("\nMao Inicial: ");
		j->ImprimirMao();
		Wait();
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
	return (jogadores[jogadorAtual].QuantidadeCartasMao() == 0);
}

Carta Burro::ComprarCartaDoBaralho()
{
	Carta c = cartas.RetirarCarta(-1);
	return c;
}

void Burro::FimDeJogo(int vencedor)
{
	LimparTerminal();
	printf("\nFim de jogo");
	printf("\nVencedor: Jogador %d", vencedor);
}

int Burro::JogadorComMenosCartas()
{
	int menorQuantidade = 52;
	int jogadorMenosCartas;
	
	for(int i = 0; i < quantidadeJogadores; i++)
	{
		if(jogadores[i].QuantidadeCartasMao() < menorQuantidade)
		{
			menorQuantidade = jogadores[i].QuantidadeCartasMao();
			jogadorMenosCartas = i + 1;
		}
	}
	
	return jogadorMenosCartas;
}

void Burro::LoopPartida()
{
#ifdef DEBUG_Burro_LoopPartida
	cartas.ImprimeBaralho(); 
	Wait();
#endif 

	int posicaoCarta = 0;
	int jogadorMaiorCarta = 0;
	Carta maiorCarta;
	
	while(true)
	{
		LimparTerminal();
		printf("\n----------------Rodada %d----------------------", rodadas);
		printf("\nQuantidade de cartas na mesa: %d", cartas.QuantidadeCartas());
		mesa.Imprimir();
		printf("\nVez do Jogador %d", jogadorAtual +  1);
		jogadores[jogadorAtual].ImprimirMao();
		int cartasCompradas = 0;
		while(!jogadores[jogadorAtual].CartaDisponivel(mesa.GetNaipe()))
		{
			if(cartas.QuantidadeCartas() == 0)
			{
				FimDeJogo(JogadorComMenosCartas());
				return;
			}
			
			if(cartasCompradas == 0)
			{
				printf("\nVoce nao tem cartas desse naipe: hora de comprar");
				Wait();
			}
			
			Carta cartaComprada = ComprarCartaDoBaralho();
			jogadores[jogadorAtual].AdicionarCartaNaMao(cartaComprada);
#ifdef DEBUG_Burro_LoopPartida
			printf("\nComprando carta: ");
			cartaComprada.ImprimeCarta();
#endif
			++cartasCompradas;
		}
		
		if(cartasCompradas != 0)
		{
			printf("\nVoce comprou %d cartas", cartasCompradas);
			jogadores[jogadorAtual].ImprimirMao();
		}
		
		posicaoCarta = jogadores[jogadorAtual].EscolherCartaParaJogar(mesa.GetNaipe());
		Carta c = jogadores[jogadorAtual].JogarCarta(posicaoCarta);
		mesa.AdicionarCarta(c);
		
#ifdef DEBUG_Burro_LoopPartida
		printf("\nCarta escolhida pelo jogador: ");
		c.ImprimeCarta();
		printf("\nQuantidade de cartas: %d", jogadores[jogadorAtual].QuantidadeCartasMao());
		printf("\nMao do jogador apos a rodada: ");
		jogadores[jogadorAtual].ImprimirMao();
		Wait();
#endif

		if (ChecaFimJogo())
		{
			FimDeJogo(jogadorAtual + 1);
			return;
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
			Wait();
			SetJogadorAtual(jogadorMaiorCarta);
		}
		else
		{
			MudaJogadorAtual();
		}
	
		IncrementaRodada();
	}
}