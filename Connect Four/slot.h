#ifndef SLOT_H
#define SLOT_H
#include "token.h"
#include <memory>

class Slot
{
public:

	enum State
	{
		empty,
		filled,
		max_states
	};

	Slot() = default;

	bool isEmpty() const;
	const State& getState() const;
	const Token* getToken() const;
	void addToken(Token token);
	friend std::ostream& operator<< (std::ostream& out, const State& state);
	friend std::ostream& operator<< (std::ostream& out, const Slot& slot);
	bool operator== (const Slot& slot) const;
	bool operator!= (const Slot& slot) const;

private:

	State m_state{ empty };
	std::unique_ptr<Token> m_token;
};

#endif