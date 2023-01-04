class Mesa
{
private:
	Baralho cartas;
	int jogadores[MAX_JOGADORES];
	
public:
	Mesa();
	void Imprimir();
	void AdicionarCarta(Carta c, int jogador);
	void Limpar();
	int QuantidadeCartas();
	char GetNaipe();
	void LimparArrayJogadores();
};
