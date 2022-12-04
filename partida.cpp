#include "baralho.cpp"


int main ()
{
	Baralho bar1 = Baralho();
	bar1.Embaralhar();
	bar1.ImprimeBaralho();
	vector<Carta> bar2 = bar1.Distribuir(1);
	bar1.ImprimeCarta(bar2[0]); 
	return 0;
}