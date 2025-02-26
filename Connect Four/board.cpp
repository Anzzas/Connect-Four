#include "board.h"

const Point2D& Board::getBoard() const
{
	return m_board;
}

std::ostream& operator<< (std::ostream& out, const Board& board)
{
	// Print column number
	for (int count{ 0 }; count < boardSettings::columns; count++)
	{
		out << " " << count + 1 << "  ";
	}

	out << "\n";

	// Print each slots
	for (size_t y{ 0 }; y < boardSettings::rows; y++)
	{
		for (size_t x{ 0 }; x < boardSettings::columns; x++)
		{
			out << board.m_board[y][x] << " ";
		}
		out << "\n\n";
	}
	return out;
}

bool Board::isColumnFull(size_t column) const
{
	size_t choosenColumn{ column - 1 };
	for (size_t y{ 0 }; y < boardSettings::rows; y++)
	{
		if (m_board[y][choosenColumn].isEmpty())
			return false;
	}
	return true;
}

bool Board::isBoardFull() const
{
	for (size_t y{ 0 }; y < boardSettings::rows; y++)
	{
		for (size_t x{ 0 }; x < boardSettings::columns; x++)
		{
			if (m_board[y][x].isEmpty())
				return false;
		}
	}
	return true;
}

void Board::dropCoin(Token token, size_t column)
{
	if (isColumnFull(column))
		throw std::runtime_error{ "Error : Tried to add an token on a full column !" };

	size_t choosenColumn{ column - 1 };

	for (size_t y{ 0 }; y < boardSettings::rows; y++)
	{
		if (m_board[y][choosenColumn].getState() == Slot::filled)
		{
			m_board[y - 1][choosenColumn].addToken(token);
			return;
		}
	}

	// If last bottom slot of the selected row is empty then it fill it with the player token
	if (m_board[boardSettings::rows - 1][choosenColumn].isEmpty())
		m_board[boardSettings::rows - 1][choosenColumn].addToken(token);
}

bool Board::isGameWon() const
{
	
	if (checkLinearCombinations() || checkDiagonalsCombinations())
		return true;

	return false;
}

bool Board::checkDiagonalsCombinations() const
{
	// Diagonales descendantes (haut-gauche à bas-droite)
	for (size_t y{ 0 }; y < boardSettings::rows; y++)
	{
		for (size_t x{ 0 }; x < boardSettings::columns; x++)
		{
			if ((y + 3 < boardSettings::rows) && (x + 3 < boardSettings::columns))
			{
				if (m_board[y][x] == m_board[y + 1][x + 1] && m_board[y + 1][x + 1] == m_board[y + 2][x + 2] && m_board[y + 2][x + 2] == m_board[y + 3][x + 3])
					return true;
			}
		}
	}

	// Diagonales montantes (bas-gauche à haut-droite)
	for (int y{ boardSettings::rows - 1 }; y >= 0; y--)
	{
		for (size_t x{ 0 }; x < boardSettings::columns; x++)
		{
			if ((y - 3 >= 0) && (x + 3 < boardSettings::columns))
			{
				if (m_board[static_cast<size_t>(y)][x] == m_board[static_cast<size_t>(y - 1)][x + 1] && m_board[static_cast<size_t>(y - 1)][x + 1] == m_board[static_cast<size_t>(y - 2)][x + 2] && m_board[static_cast<size_t>(y - 2)][x + 2] == m_board[static_cast<size_t>(y - 3)][x + 3])
					return true;
			}
		}
	}
	return false;
}

bool Board::checkLinearCombinations() const
{
	for (size_t y{ 0 }; y < boardSettings::rows; y++)
	{
		for (size_t x{ 0 }; x < boardSettings::columns; x++)
		{

			// Check winning row combination
			if (x + 3 < boardSettings::columns)
			{
				if (m_board[y][x] == m_board[y][x + 1] && m_board[y][x + 1] == m_board[y][x + 2] && m_board[y][x + 2] == m_board[y][x + 3])
					return true;
			}

			// Check winning column combination
			if (y + 3 < boardSettings::rows)
			{
				if (m_board[y][x] == m_board[y + 1][x] && m_board[y + 1][x] == m_board[y + 2][x] && m_board[y + 2][x] == m_board[y + 3][x])
					return true;
			}
		}
	}
	return false;
}


void Board::undoMove(int col) 
{
	for (int row = 0; row < boardSettings::rows; row++) 
	{
		if (!m_board[row][col].isEmpty())  // Vérifie si la case contient un jeton
		{ 
			m_board[row][col].clear(); // Réinitialise la case (la met vide)
			break;
		}
	}
}
