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
	
	// Iniciar mao dos jogadores
	for (auto j = jogadores.rbegin(); j != jogadores.rend(); ++j)
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