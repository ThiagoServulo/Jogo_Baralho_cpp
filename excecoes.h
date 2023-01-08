class BurroException: public exception 
{ 
	const char * msg; 
	BurroException(); 
public: 
	BurroException(const char * s) noexcept(true): msg(s) {} 
	const char * what() const noexcept(true) { return msg; } 
};

void ThrowJogadoresException();