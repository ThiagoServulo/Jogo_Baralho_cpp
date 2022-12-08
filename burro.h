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
	int GetNumeroJogadorAtual();
};
