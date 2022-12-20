class Burro
{
private:
	Baralho cartas;
	Mesa mesa;
	int rodadas;
	int quantidadeJogadores;
	int jogadorAtual;
	vector<Jogador> jogadores;
	
public:
	Burro();
	Mesa GetMesa();
	int GetRodadas();
	int GetQuantidadeJogadores();
	Baralho GetBaralho();
	vector<Jogador> GetJogadores();
	void ConfiguraJogo();
	void InicializaJogadores();
	void MudaJogadorAtual();
	void SetJogadorAtual(int numeroJogador);
	void IncrementaRodada();
	bool ChecaFimRodada();
	bool ChecaFimJogo();
	Carta ComprarCartaDoBaralho();
	void LoopPartida();
	void FimDeJogo(int vencedor);
	int JogadorComMenosCartas();
};
