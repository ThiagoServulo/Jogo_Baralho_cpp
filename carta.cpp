#include "carta.h"

char Naipes[4] =
{
    'O', // Ouros
    'C', // Copas
    'E', // Espadas
    'P'  // Paus
};

char Tipos[14]
{
	'1', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'V', 'D', 'R', 'A'
};

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
	}
	
	// Lançar Excessão
	printf("\nERRO");
	return false;
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

