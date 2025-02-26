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

		const std::array<const std::unique_ptr<Player>, 2> players{

			std::make_unique<Player>(),
			std::make_unique<Cpu>(),
		};

		std::cout << "Welcome to Connect Four !\n"
			<< "You have the red tokens. Your opponant has the yellow ones !\n\n";

		bool continueGame{ true };
		while (continueGame)
		{
			std::cout << board << "\n\n\n";

			for (auto& e : players)
			{
				try { e->playTurn(board); }

				catch (const std::runtime_error& error) // Fatal error handling
				{
					std::cerr << error.what();
					return 0;
				}

				// Verifying Win or Draw conditions
				if (board.isGameWon() || board.isBoardFull())
				{
					std::cout << board << "\n\n";

					if (board.isGameWon())
						std::cout << e->getName() << " has won !\n\n";

					else
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