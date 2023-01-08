/*
 * @file partida.cpp
 * @version 1.0
 * @date 07/01/2023
 * @author Thiago Sérvulo Guimarães
 */

using namespace std;
#include <cstddef> 
#include <algorithm>
#include <random>
#include <chrono>  
#include <tuple>
#include <vector>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "utils.h"
#include "excecoes.cpp"
#include "carta.cpp"
#include "baralho.cpp"
#include "jogador.cpp"
#include "mesa.cpp"
#include "burro.cpp"
 
/*
 * @brief Função main, entry point da aplicação
 */
int main ()
{
	Burro partidaBurro = Burro();
	
	partidaBurro.LoopPartida();

	return 0;
} 