#ifndef BOARD_H
#define BOARD_H
#include "slot.h"

namespace boardSettings
{
	constexpr int columns{ 7 };
	constexpr int rows{ 6 };
}

using Point2D = std::array<std::array<Slot, boardSettings::columns>, boardSettings::rows>;

class Board
{
public:

	Board() = default;

	const Point2D& getBoard() const;
	void dropCoin(Token token, size_t column);
	friend std::ostream& operator<< (std::ostream& out, const Board& board);
	bool isColumnFull(size_t column) const;
	bool isBoardFull() const;
	bool isGameWon() const;

private:

	Point2D m_board{};
};

#endif
