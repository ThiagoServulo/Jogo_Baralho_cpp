#include <algorithm>
#include <random>
#include <chrono>  
#include "baralho.h"

Baralho::Baralho()
{
	MontaBaralho(1);
}

Baralho::Baralho(int quantBaralhos)
{
	MontaBaralho(quantBaralhos);
}

void Baralho::MontaBaralho(int quantBaralhos)
{
	for(int i; i < quantBaralhos; i++)
	{
		for(char c : CartasTipos)
		{
			for(char n : NaipesTipos)
			{
				cartas.push_back(make_tuple(c, n));
			}
		}
	}
}

void Baralho::Embaralhar()
{
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(begin(cartas), end(cartas), default_random_engine(seed));
}

void Baralho::ImprimeBaralho()
{
	printf("\n\n");
	for(auto c: cartas)
	{
		ImprimeCarta(c);
	}
}

void Baralho::ImprimeCarta(Carta c)
{
	printf("%c%c  ", get<0>(c), get<1>(c));
} 
 
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

int Baralho::QuantidadeCartas()
{
	return cartas.size();
}

