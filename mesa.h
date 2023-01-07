/*
 * @file mesa.h
 * @version 1.0
 * @date 07/01/2023
 * @author Thiago Sérvulo Guimarães
 */

class Mesa
{
private:
	Baralho cartas;
	int jogadores[MAX_JOGADORES];
	
public:
	Mesa();
	void Imprimir();
	void AdicionarCarta(Carta carta, int jogador);
	void Limpar();
	int QuantidadeCartas();
	char GetNaipe();
	void LimparArrayJogadores();
};
