#ifndef PLAYER_H
#define PLAYER_H
#include "board.h"

class Player
{
public:

	Player() = default;
	virtual ~Player() = default;

	virtual void playTurn(Board& board) const;

private:

	size_t chooseColumn(const Board& board) const;
};

#endif