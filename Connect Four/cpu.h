#ifndef CPU_H
#define CPU_H
#include "player.h"

class Cpu : public Player
{
public:

	Cpu()
		: Player{ "Yellow" }
	{
	}

	void playTurn(Board& board) const override;
};

#endif