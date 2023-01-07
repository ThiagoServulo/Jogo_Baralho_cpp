/*
 * @file jogador.h
 * @version 1.0
 * @date 07/01/2023
 * @author Thiago Sérvulo Guimarães
 */

class Jogador
{
private:
	int numJogador;
	int quantidadeCartas;
	Baralho Mao;
	
public:
	Jogador(int num);
	int GetNumero();
	void IniciarMao(Baralho baralho);
	void ImprimirMao();
	Carta JogarCarta(int posicao);
	int EscolherCartaParaJogar(char naipeMesa);
	int QuantidadeCartasMao();
	bool CartaDisponivel(char naipeMesa);
	void AdicionarCartaNaMao(Carta carta);
};
