#include "cpu.h"
#include "random.h"

void Cpu::playTurn(Board& board) const
{
	size_t randomChoice{ static_cast<size_t>(Random::get(1, 7)) };
	while (true)
	{
		if (board.isColumnFull(randomChoice))
		{
			randomChoice = static_cast<size_t>(Random::get(1, 7));
			continue;
		}
		break;
	}
	try { board.dropCoin(Token::createYellow(), randomChoice); }

	catch (const std::runtime_error&) { throw; }
}