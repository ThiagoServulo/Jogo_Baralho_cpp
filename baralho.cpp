/*
 * @file baralho.cpp
 * @version 1.0
 * @date 07/01/2023
 * @author Thiago Sérvulo Guimarães
 */
 
#include "baralho.h"

/*
 * @brief Construtor da classe Baralho
 */
Baralho::Baralho()
{
	MontaBaralho(1);
}

/*
 * @brief Construtor da classe Baralho
 * @param quantBaralhos Quantidade de baralhos usados no jogo
 */
Baralho::Baralho(int quantBaralhos)
{
	MontaBaralho(quantBaralhos);
}

/*
 * @brief Construtor da classe Baralho
 * @param vetorCartas Cartas a serem iniciadas neste baralho
 */
Baralho::Baralho(vector<Carta> vetorCartas)
{
	cartas = vetorCartas;
}

/*
 * @brief Montar o baralho do jogo usando os naipes e cartas padrão
 * @param quantBaralhos Quantidade de baralhos usados no jogo
 */
void Baralho::MontaBaralho(int quantBaralhos)
{
	for(int i; i < quantBaralhos; i++)
	{
		for(char c : Tipos)
		{
			for(char n : Naipes)
			{
				cartas.push_back(Carta(n, c));
			}
		}
	}
}

/*
 * @brief Embaralha as cartas do baralho
 */
void Baralho::Embaralhar()
{
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(begin(cartas), end(cartas), default_random_engine(seed));
}

/*
 * @brief Imprime as cartas de um baralho
 */
void Baralho::ImprimeBaralho()
{
	printf("\n");
	for(auto c: cartas)
	{
		c.ImprimeCarta();
		printf("  ");
	}
}
 
 /*
 * @brief Distribui e retorna o número de cartas desejadas
 * @param quantCartas Quantidade de cartas desejadas
 * @return Vetor com as cartas distribuídas
 */
vector<Carta> Baralho::Distribuir(int quantCartas)
{
	vector<Carta> cartasDistribuidas;
	for(int i = 0; i < quantCartas; i++)
	{
		auto carta = cartas[QuantidadeCartas() - 1];
		cartas.pop_back();
		cartasDistribuidas.push_back(carta);
	}
	return cartasDistribuidas;
}

 /*
 * @brief Quantidade de cartas que o baralho contém
 * @return Número de cartas no baralho
 */
int Baralho::QuantidadeCartas()
{
	return cartas.size();
}

 /*
 * @brief Retira uma carta do baralho de acordo com a posição desejada
 * @param posicao Posição de onde a carta será retirada
 * @return Carta retirada
 */
Carta Baralho::RetirarCarta(int posicao)
{
	Carta c;
	
	if(posicao == -1) // última carta
	{
		c = cartas.back();
		cartas.pop_back();
	}
	else
	{	
		--posicao;
		c = cartas[posicao];
		cartas.erase(cartas.begin() + posicao);
	}
	
	return c;
}

 /*
 * @brief Adiciona uma carta na última posição do baralho
 * @param carta Carta a ser adicionada
 */
void Baralho::AdicionarCarta(Carta carta)
{
	cartas.push_back(carta);
}

 /*
 * @brief Excluí todas as cartas do baralho
 */
void Baralho::ExcluirTodasCartas()
{
	cartas.clear();
}

 /*
 * @brief Escolhe e seleciona uma carta baseada na posição desejada
 * @param posicao Posição da carta a ser selecionada
 * @return true  - se a posição for válida
 *         false - se a posição for inválida
 */
bool Baralho::EscolherCarta(int posicao)
{
	--posicao;
	return (posicao < 0 || posicao >= QuantidadeCartas()) ? false : true;
}

 /*
 * @brief Acessa uma carta baseada na posição desejada
 * @param posicao Posição da carta a ser acessada
 * @return Carta que se encontra na posição informada
 */
Carta Baralho::AcessarCarta(int posicao)
{
	--posicao;
	return cartas[posicao];
}