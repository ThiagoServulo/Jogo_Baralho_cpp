char NaipesTipos[4] =
{
    'O', // Ouros
    'C', // Copas
    'E', // Espadas
    'P'  // Paus
};

char CartasTipos[14]
{
	'A', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'V', 'D', 'R' 
};

class Baralho
{
private:
	vector<Carta> cartas;
	void MontaBaralho(int quantBaralhos);
	
public:
	Baralho();
	Baralho(int quantBaralhos);
	void ImprimeBaralho();
	void ImprimeCarta(Carta c);
	void Embaralhar();
	vector<Carta> Distribuir(int quantCartas);
	int QuantidadeCartas();
};
