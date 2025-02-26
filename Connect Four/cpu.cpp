#include "cpu.h"
#include "random.h"

int minimax(Board& board, int depth, int alpha, int beta, bool maximizingPlayer) 
{
	if (board.isGameWon()) 
		return maximizingPlayer ? -CpuSettings::WINNING_SCORE + depth : CpuSettings::WINNING_SCORE - depth;

	if (board.isBoardFull() || depth == 0) 
		return 0;

	if (maximizingPlayer) 
	{
		int maxEval = std::numeric_limits<int>::min();

		for (int col = 0; col < boardSettings::columns; col++) 
		{
			if (!board.isColumnFull(col + 1)) 
			{
				board.dropCoin(Token::createYellow(), col + 1);
				int eval = minimax(board, depth - 1, alpha, beta, false);
				board.undoMove(col);
				maxEval = std::max(maxEval, eval);
				alpha = std::max(alpha, eval);

				if (beta <= alpha) 
					break;
			}
		}
		return maxEval;
	}
	else {
		int minEval = std::numeric_limits<int>::max();
		for (int col = 0; col < boardSettings::columns; col++) 
		{
			if (!board.isColumnFull(col + 1)) 
			{
				board.dropCoin(Token::createRed(), col + 1);
				int eval = minimax(board, depth - 1, alpha, beta, true);
				board.undoMove(col);
				minEval = std::min(minEval, eval);
				beta = std::min(beta, eval);

				if (beta <= alpha) 
					break;
			}
		}
		return minEval;
	}
}

size_t Cpu::findBestMove(Board& board) 
{
	int bestMove = -1;
	int bestScore = std::numeric_limits<int>::min();

	for (int col = 0; col < boardSettings::columns; col++) 
	{
		if (!board.isColumnFull(col + 1)) 
		{
			board.dropCoin(Token::createYellow(), col + 1);
			int moveScore = minimax(board, CpuSettings::SEARCH_DEPTH, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), false);
			board.undoMove(col);
			if (moveScore > bestScore) {
				bestScore = moveScore;
				bestMove = col;
			}
		}
	}
	return static_cast<size_t>(bestMove);
}

void Cpu::playTurn(Board& board)
{
	size_t bestMove{ findBestMove(board) };
	if (bestMove != static_cast<size_t>(-1))
	{
		board.dropCoin(Token::createYellow(), bestMove + 1);
	}

	//try { board.dropCoin(Token::createYellow(), randomChoice.value() + 1); }

	//catch (const std::runtime_error&) { throw; }
}

/*std::optional<size_t> Cpu::getWinningMove(const Board& board) const
{
	const Point2D& m_board = board.getBoard();

	for (size_t y{ 0 }; y < boardSettings::rows; y++)
	{
		for (size_t x{ 0 }; x < boardSettings::columns; x++)
		{

			// Check winning row combination
			if (x + 3 < boardSettings::columns)
			{
				if (m_board[y][x] == m_board[y][x + 1] && m_board[y][x + 1] == m_board[y][x + 2] && m_board[y][x + 3].isEmpty())
					return x + 3;
			}

			// Check winning column combination
			if (y + 3 < boardSettings::rows)
			{
				if (m_board[y][x].isEmpty() && m_board[y + 1][x] == m_board[y + 2][x] &&  m_board[y + 2][x] == m_board[y + 3][x])
					return x;
			}
		}
	}
	return std::nullopt;
}*/