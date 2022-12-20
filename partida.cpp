using namespace std;
#include <cstddef> 
#include <algorithm>
#include <random>
#include <chrono>  
#include <tuple>
#include <vector>
#include <iostream>
#include "utils.h"
#include "carta.cpp"
#include "baralho.cpp"
#include "jogador.cpp"
#include "mesa.cpp"
#include "burro.cpp"
 

int main ()
{
	Burro partidaBurro = Burro();
	
	partidaBurro.LoopPartida();

	return 0;
}