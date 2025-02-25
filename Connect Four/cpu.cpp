#include "cpu.h"

void Cpu::playTurn(Board& board) const
{
	if (board.isColumnFull(2))
	{
		//To continue here
	}

	try { board.dropCoin(Token::createYellow(), 2); }

	catch (const std::runtime_error&) { throw; }
}