/*
 * @file burro.cpp
 * @version 1.0
 * @date 04/01/2023
 * @author Thiago Sérvulo Guimarães
 */
 
#include "burro.h"

/*
 * @brief Construtor da classe Burro
 */
Burro::Burro()
{
	cartas = Baralho();
	cartas.Embaralhar();
	mesa = Mesa();
	ConfiguraJogo();
	rodadas = 1;
}

/*
 * @brief Lê do teclado e configura a quantidade de jogadores na partida
 */
void Burro::ConfiguraJogo()
{
	while(true)
	{
		// Lendo a quantidade de jogadores
		printf("Escolha a quantidade de jogadores (entre %d e %d): ", MIN_JOGADORES, MAX_JOGADORES);
		scanf("%d", &quantidadeJogadores);
		if(quantidadeJogadores >= MIN_JOGADORES && quantidadeJogadores <= MAX_JOGADORES)
		{
			InicializaJogadores();
			break;
		}
		LimparTerminal();
	}
}

/*
 * @brief Distribui as cartas e inicializa as mãos dos jogadores
 */
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
			ThrowJogadoresException();
			break;
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

/*
 * @brief Muda o jogador atual, seguindo a ordem convencional
 */
void Burro::MudaJogadorAtual()
{
	jogadorAtual = jogadorAtual == (quantidadeJogadores - 1) ? 0 : ++jogadorAtual;
}

/*
 * @brief Muda o jogador atual, setando conforme informado
 * @param numeroJogador Número do jogador que será setado como atual
 */
void Burro::SetJogadorAtual(int numeroJogador)
{
	jogadorAtual = numeroJogador;
}

/*
 * @brief Incrementa o número de rodadas já jogadas
 */
void Burro::IncrementaRodada()
{
    ++rodadas;
}

/*
 * @brief Checa se a rodada chegou ao fim
 * @return true  - se a rodada estiver concluída
 *         false - se a rodada ainda não estiver concluída
 */
bool Burro::ChecaFimRodada()
{
	return (rodadas % quantidadeJogadores) == 0;
}

/*
 * @brief Checa se a partida chegou ao fim, analizando a quantidade de cartas que cada jogador possui
 * @return true  - se a partida estiver concluída
 *         false - se a partida ainda não estiver concluída
 */
bool Burro::ChecaFimJogo()
{
	return (jogadores[jogadorAtual].QuantidadeCartasMao() == 0);
}

/*
 * @brief Compra uma carta na pilha de compras
 * @return Retorna a carta comprada
 */
Carta Burro::ComprarCartaDoBaralho()
{
	Carta c = cartas.RetirarCarta(-1);
	return c;
}

/*
 * @brief Imprime a mensagem de fim de jogo e o jogador vencedor
 * @param vencedor Número do jogador vencedor
 */
void Burro::FimDeJogo(int vencedor)
{
	LimparTerminal();
	printf("\nFim de jogo");
	for (auto j = jogadores.begin(); j != jogadores.end(); ++j)
	{	
		printf("\nJogador: %d. Quantidade de cartas: %d", j->GetNumero(), j->QuantidadeCartasMao());
	}
	printf("\nVencedor: Jogador %d", vencedor);
}

/*
 * @brief Verifica e retorna o número do jogador com menos cartas na mão
 * @return Número do jogador com menos cartas na mão
 */
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

/*
 * @brief Imprime as informações da mesa (número da rodada e as cartas já jogadas)
 */
void Burro::ImprimirMesa()
{
	LimparTerminal();
	printf("\n----------------Rodada %d----------------------", rodadas);
	printf("\nQuantidade de cartas na compra: %d", cartas.QuantidadeCartas());
	mesa.Imprimir();
}

/*
 * @brief Finaliza a rodada, imprimindo seu vencedor e definindo o jogador atual
 * @param jogadorVencedorDaRodada Número do jogador que venceu a rodada
 */
void Burro::FinalizarRodada(int jogadorVencedorDaRodada)
{
	ImprimirMesa();
	printf("\nO jogador %d venceu a rodada\n", jogadorVencedorDaRodada + 1);
	Wait();
	SetJogadorAtual(jogadorVencedorDaRodada);
}

/*
 * @brief Loop da partida, responsável por processar e controlar o fluxo do jogo
 */
void Burro::LoopPartida()
{
#ifdef DEBUG_Burro_LoopPartida
	cartas.ImprimeBaralho(); 
	Wait();
#endif 

	int posicaoCarta = 0;
	int jogadorMaiorCarta = 0;
	Carta maiorCarta;
	
	// Loop do jogo
	while(true)
	{
		ImprimirMesa();
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
		mesa.AdicionarCarta(c, jogadorAtual);
		
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
			FinalizarRodada(jogadorMaiorCarta);
			mesa.Limpar();
		}
		else
		{
			MudaJogadorAtual();
		}
		
		IncrementaRodada();
	}
}