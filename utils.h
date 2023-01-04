vector<char> Tipos = { '1', '2', '3', '4', '5', '6', '7', '8', '9', 'D', 'J', 'Q', 'K', 'A' };

vector<char> Naipes =
{
    'O', // Ouros
    'C', // Copas
    'E', // Espadas
    'P'  // Paus
};

//Macros
#define MAX_JOGADORES   4

// Defines de LOG
//#define DEBUG_Burro_LoopPartida            
//#define DEBUG_Burro_InicializaJogadores    
//#define DEBUG_Jogador_EscolherCartaParaJogar

// Defines de Cores
#define DEFAULT      15
#define BLACK_CARDS  112
#define RED_CARDS    116

void Wait()
{
	printf("\n");
	system("pause");
}

void PrintAndWait(char * msg)
{
	puts(msg);
	Wait();
}

void LimparTerminal()
{
	system("cls");
}