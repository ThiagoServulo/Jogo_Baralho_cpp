/*
 * @file carta.h
 * @version 1.0
 * @date 07/01/2023
 * @author Thiago Sérvulo Guimarães
 */

class Carta
{
private:
	char naipe;
	char tipo;
	
public:
	Carta(char n, char t);
	Carta();
	bool operator > (const Carta & c);
	void ImprimeCarta();
	char GetNaipe();
	char GetTipo();
};

