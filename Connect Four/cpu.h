#ifndef CPU_H
#define CPU_H
#include "player.h"
#include <optional>
#include <limits>

namespace CpuSettings
{
	constexpr int WINNING_SCORE = 1000;
	constexpr int SEARCH_DEPTH = 5;
}

class Cpu : public Player
{
public:

	Cpu()
		: Player{ "Yellow" }
	{
	}

	void playTurn(Board& board) override;
	//bool isWinningMove(const Board& board) const;
	//std::optional<size_t> getWinningMove(const Board& board) const;
	size_t findBestMove(Board& board);
};

#endif