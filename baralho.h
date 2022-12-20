class Baralho
{
private:
	vector<Carta> cartas;
	void MontaBaralho(int quantBaralhos);
	
public:
	Baralho();
	Baralho(int quantBaralhos);
	Baralho(vector<Carta> c);
	void ImprimeBaralho();
	void Embaralhar();
	vector<Carta> Distribuir(int quantCartas);
	int QuantidadeCartas();
	Carta RetirarCarta(int posicao);
	void AdicionarCarta(Carta c);
	void ExcluirTodasCartas();
	bool EscolherCarta(int posicao);
	Carta AcessarCarta(int posicao);
};
