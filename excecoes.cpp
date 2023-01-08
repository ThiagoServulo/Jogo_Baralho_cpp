#include <iostream> 
#include <exception> 
#include "excecoes.h"

BurroException JogadoresException("Quantidade de jogadores invalida");

// Função que lança a exceção 
void ThrowJogadoresException() 
{ 
	throw JogadoresException; 
}
	