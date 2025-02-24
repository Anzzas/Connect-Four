#include "slot.h"

int main()
{
	Slot slot{};
	slot.addToken(Token::createRed());

	Slot slot2{};

	std::cout << slot.getToken()->getType();
}