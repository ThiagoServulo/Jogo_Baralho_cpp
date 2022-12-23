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
}

void Carta::ImprimeCarta()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (naipe == 'O' || naipe == 'C') ? RED_CARDS : BLACK_CARDS);
	printf("%c%c", tipo, naipe);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DEFAULT);
} 

char Carta::GetNaipe()
{
	return naipe;
}

char Carta::GetTipo()
{
	return tipo;
}

