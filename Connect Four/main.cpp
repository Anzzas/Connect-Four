#include "cpu.h"

bool replayGame()
{
	std::cout << "Replay game ? (y/n): ";
	char choice{};

	while (true)
	{
		std::cin >> choice;

		if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (choice == 'Y' || choice == 'y')
			return true;
		else if (choice == 'N' || choice == 'n')
			return false;

		std::cout << "Wrong input! Try again (y/n): ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

int main()
{
	while (true)
	{
		Board board{};

		const std::array<const std::unique_ptr<const Player>, 2> players{

			std::make_unique<Player>(),
			std::make_unique<Cpu>(),
		};

		std::cout << "Welcome to Connect Four !\n"
			<< "You have the red tokens. Your opponant has the yellow ones !\n\n";

		while (bool continueGame{ true })
		{
			std::cout << board << "\n\n\n";

			for (const auto& e : players)
			{
				try { e->playTurn(board); }

				catch (const std::runtime_error& error)
				{
					std::cerr << error.what();
					return 0;
				}

				// Verify Draw condition
				if (board.isBoardFull())
				{
					std::cout << "It is a draw !\n\n";
					continueGame = false;
					break;
				}
			}
		}

		if (!replayGame())
			return 0;
	}
}