class Burro
{
private:
	Baralho cartas;
	Mesa mesa;
	int rodadas;
	int quantidadeJogadores;
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
};
