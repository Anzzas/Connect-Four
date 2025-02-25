#include "player.h"

size_t Player::chooseColumn(const Board& board) const
{
	std::cout << "Enter the column number you want to play: ";
	size_t choice{};

	while (true)
	{
		std::cin >> choice;

		if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong input! Try again: ";
			continue;
		}
		else if (choice <= 0 || choice > boardSettings::columns)
		{
			std::cout << "Please enter a number between 1 and 7: ";
			continue;
		}
		else if (board.isColumnFull(choice))
		{
			std::cout << "Column is full! Try again: ";
			continue;
		}

		std::cout << "\n\n";
		return choice;
	}
}

void Player::playTurn(Board& board) const
{
	size_t column{ chooseColumn(board) };

	try { board.dropCoin(Token::createRed(), column); }

	catch (const std::runtime_error&) { throw; }
}

const std::string& Player::getName() const { return m_name; }