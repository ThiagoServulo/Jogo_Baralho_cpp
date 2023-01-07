/*
 * @file carta.cpp
 * @version 1.0
 * @date 07/01/2023
 * @author Thiago Sérvulo Guimarães
 */
 
#include "carta.h"

/*
 * @brief Construtor da classe Baralho
 */
Carta::Carta()
{
	
}

/*
 * @brief Construtor da classe Baralho
 * @param n Naipe da carta
 * @param t Tipo da carta
 */
Carta::Carta(char n, char t)
{
	naipe = n;
	tipo = t;
}

/*
 * @brief Operador de comparação entre as cartas, baseado no tipo da carta
 * @param c Carta a ser comparada
 * @param true  - Se a carta atual for maior que a informada
 *        false - Se a carta atual for menor que a informada
 */
bool Carta::operator > (const Carta & c)
{
	return find(Tipos.begin(), Tipos.end(), tipo) > find(Tipos.begin(), Tipos.end(), c.tipo);
}

/*
 * @brief Imprime a carta (naipe e tipo)
 */
void Carta::ImprimeCarta()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (naipe == 'O' || naipe == 'C') ? RED_CARDS : BLACK_CARDS);
	printf("%c%c", tipo, naipe);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFAULT);
} 

/*
 * @brief Retorna o naipe da carta
 * @return Naipe da carta
 */
char Carta::GetNaipe()
{
	return naipe;
}

/*
 * @brief Retorna o tipo da carta
 * @return Tipo da carta
 */
char Carta::GetTipo()
{
	return tipo;
}

