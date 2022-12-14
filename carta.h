
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

