/*
 * @file mesa.cpp
 * @version 1.0
 * @date 07/01/2023
 * @author Thiago Sérvulo Guimarães
 */
 
#include "mesa.h"

/*
 * @brief Construtor da classe Mesa
 */
Mesa::Mesa()
{
	cartas = Baralho();
	LimparArrayJogadores();
}

/*
 * @brief Imprime os dados da mesa
 */
void Mesa::Imprimir()
{
	printf("\n---------------------Mesa---------------------");
	cartas.ImprimeBaralho();
	printf("\n");
	for(int i = 0; i < cartas.QuantidadeCartas() ; i++)
	{ 
		printf("J%d  ", jogadores[i]);
	}
	printf("\n----------------------------------------------");
}

/*
 * @brief Adiciona a carta jogada pelo jogador na mesa
 * @param carta Carta a ser adiconada
 * @param jogador Número do jogador que jogou a carta
 */
void Mesa::AdicionarCarta(Carta carta, int jogador)
{
	jogadores[cartas.QuantidadeCartas()] = ++jogador;
	cartas.AdicionarCarta(carta);
}

/*
 * @brief Limpa os dados da mesa
 */
void Mesa::Limpar()
{
	cartas.ExcluirTodasCartas();
	LimparArrayJogadores();
}

/*
 * @brief Cartas que estão disponíveis para serem compradas
 * @return Quantidade de cartas disponíveis para serem compradas
 */
int Mesa::QuantidadeCartas()
{
	return cartas.QuantidadeCartas();
}

/*
 * @brief Retorna o naipe das cartas que estão na mesa
 * @return Naipe das cartas que estão na mesa
 */
char Mesa::GetNaipe()
{
	return cartas.QuantidadeCartas() == 0 ? ' ' : cartas.AcessarCarta(1).GetNaipe();
}

/*
 * @brief Limpa e reseta o array de jogadores
 */
void Mesa::LimparArrayJogadores()
{
	for(int i = 0; i < MAX_JOGADORES; i++)
	{ 
		jogadores[i] = 0; 
	}
}