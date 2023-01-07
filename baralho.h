/*
 * @file baralho.h
 * @version 1.0
 * @date 07/01/2023
 * @author Thiago Sérvulo Guimarães
 */

class Baralho
{
private:
	vector<Carta> cartas;
	void MontaBaralho(int quantBaralhos);
	
public:
	Baralho();
	Baralho(int quantBaralhos);
	Baralho(vector<Carta> vetorCartas);
	void ImprimeBaralho();
	void Embaralhar();
	vector<Carta> Distribuir(int quantCartas);
	int QuantidadeCartas();
	Carta RetirarCarta(int posicao);
	void AdicionarCarta(Carta carta);
	void ExcluirTodasCartas();
	bool EscolherCarta(int posicao);
	Carta AcessarCarta(int posicao);
};
