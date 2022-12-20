
class Jogador
{
private:
	int numJogador;
	int quantidadeCartas;
	Baralho Mao;
	
public:
	Jogador(int num);
	int GetNumero();
	Baralho GetMao();
	void IniciarMao(Baralho b);
	void ImprimirMao();
	Carta JogarCarta(int posicao);
	int EscolherCartaParaJogar(char naipeMesa);
	int QuantidadeCartasMao();
	bool CartaDisponivel(char naipeMesa);
};
