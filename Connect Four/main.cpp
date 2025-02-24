#include "token.h"

int main()
{
	Token token{ Token::createRed() };
	Token token2{ Token::createRed() };

	if (token != token2)
		std::cout << "not equal\n";
	else
		std::cout << "equal\n";
}