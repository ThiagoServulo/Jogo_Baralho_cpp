
class Jogador
{
private:
	int numJogador;
	Baralho Mao;
	
public:
	Jogador(int num);
	int GetNumero();
	void IniciarMao(Baralho b);
	void ImprimirMao();
};
