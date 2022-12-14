class Mesa
{
private:
	Baralho cartas;
	
public:
	Mesa();
	void Imprimir();
	void AdicionarCarta(Carta c);
	void Limpar();
	int QuantidadeCartas();
};
