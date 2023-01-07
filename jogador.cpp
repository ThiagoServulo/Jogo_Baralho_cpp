/*
 * @file jogador.cpp
 * @version 1.0
 * @date 07/01/2023
 * @author Thiago Sérvulo Guimarães
 */
 
 #include "jogador.h"

/*
 * @brief Construtor da classe Baralho
 * @param num Número do jogador
 */
Jogador::Jogador(int num)
{
	numJogador = num;
}

/*
 * @brief Retorna o número do jogador
 * @return Número do jogador
 */
int Jogador::GetNumero()
{
	return numJogador;
}

/*
 * @brief Inicia as cartas da mão do jogador
 * @param baralho Cartas iniciais do jogador
 */
void Jogador::IniciarMao(Baralho baralho)
{
	quantidadeCartas = baralho.QuantidadeCartas();
	Mao = baralho;
}

/*
 * @brief Imprime as cartas da mão do jogador
 */
void Jogador::ImprimirMao()
{
	printf("\nSuas cartas:");
	Mao.ImprimeBaralho();
}

/*
 * @brief Retira uma carta da mão jogador, que será jogada na rodada
 * @param posicao Posição da carta que será jogada
 * @return Carta que será jogada
 */
Carta Jogador::JogarCarta(int posicao)
{
	--quantidadeCartas;
	return Mao.RetirarCarta(posicao);
}

/*
 * @brief Escolhe uma carta da mão do jogador para ser jogada
 * @param naipeMesa Naipe da carta que está na mesa
 * @return Posição da carta escolhida
 */
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

/*
 * @brief Quantidade de cartas na mão do jogador
 * @return Número de cartas na mão do jogador
 */
int Jogador::QuantidadeCartasMao()
{
	return quantidadeCartas;
}

/*
 * @brief Verifica se o jogador tem alguma carta disponível para ser jogada de acordo com o naipe que está na mesa
 * @param naipeMesa Naipe da carta que está na mesa
 * @return true  - Se existir pelo menos um carta disponível para ser jogada
 *         false - Se não existir uma carta disponível para ser jogada
 */
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

/*
 * @brief Adiciona uma carta na mão do jogador
 * @param carta Carta a ser adicionada
 */
void Jogador::AdicionarCartaNaMao(Carta carta)
{
	++quantidadeCartas;
	Mao.AdicionarCarta(carta);
}