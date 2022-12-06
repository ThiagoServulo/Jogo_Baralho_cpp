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
	'A', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'V', 'D', 'R' 
};

Carta::Carta()
{
	
}

Carta::Carta(char n, char t)
{
	naipe = n;
	tipo = t;
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