/*
 * @file burro.h
 * @version 1.0
 * @date 07/01/2023
 * @author Thiago Sérvulo Guimarães
 */

class Burro
{
private:
	// Variáveis
	Baralho cartas;
	Mesa mesa;
	int rodadas;
	int quantidadeJogadores;
	int jogadorAtual;
	vector<Jogador> jogadores;
	
	// Funções
	void ConfiguraJogo();
	void InicializaJogadores();
	void MudaJogadorAtual();
	void SetJogadorAtual(int numeroJogador);
	void IncrementaRodada();
	bool ChecaFimRodada();
	bool ChecaFimJogo();
	Carta ComprarCartaDoBaralho();
	void FimDeJogo(int vencedor);
	int JogadorComMenosCartas();
	void ImprimirMesa();
	void FinalizarRodada(int jogadorVencedorDaRodada);
	
public:
	Burro();
	void LoopPartida();
};
