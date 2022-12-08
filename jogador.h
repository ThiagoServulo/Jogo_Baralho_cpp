
class Jogador
{
private:
	int numJogador;
	Baralho Mao;
	
public:
	Jogador(int num);
	int GetNumero();
	Baralho GetMao();
	void IniciarMao(Baralho b);
	void ImprimirMao();
	Carta JogarCarta(int posicao);
	int EscolherCartaParaJogar();
	int QuantidadeCartasMao();
};
