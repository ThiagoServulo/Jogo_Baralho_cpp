
class Carta
{
private:
	char naipe;
	char tipo;
	
public:
	char Tipos[14];
	char Naipes[4];
	Carta(char n, char t);
	Carta();
	bool operator > (const Carta & c);
	void ImprimeCarta();
	char GetNaipe();
	char GetTipo();
};

