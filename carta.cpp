#include "carta.h"

Carta::Carta()
{
	
}

Carta::Carta(char n, char t)
{
	naipe = n;
	tipo = t;
}

bool Carta::operator > (const Carta & c)
{
	return find(Tipos.begin(), Tipos.end(), tipo) > find(Tipos.begin(), Tipos.end(), c.tipo);
	/*
	for(int i = 0; i < 14; i++)
	{
		if(c.tipo == Tipos[i])
		{
			return false;
		}
		
		if(tipo == Tipos[i])
		{
			return true;
		}
	}*/
	/*
	// Lançar Excessão
	printf("\nERRO");
	return false;*/
}

void Carta::ImprimeCarta()
{
	printf("%c%c  ", tipo, naipe);
} 

char Carta::GetNaipe()
{
	return naipe;
}

char Carta::GetTipo()
{
	return tipo;
}

