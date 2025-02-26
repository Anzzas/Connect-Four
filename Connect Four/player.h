#ifndef PLAYER_H
#define PLAYER_H
#include "board.h"

class Player
{
public:

	Player() = default;
	virtual ~Player() = default;

	virtual void playTurn(Board& board);
	const std::string& getName() const;

private:

	size_t chooseColumn(const Board& board) const;

protected:

	Player(std::string_view name)
		: m_name{ name }
	{
	}

		std::string m_name{"Red"};

};

#endif