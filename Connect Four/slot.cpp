#include "slot.h"

const Slot::State& Slot::getState() const
{
	return m_state;
}

const Token* Slot::getToken() const
{
	return m_token.get();
}

void Slot::addToken(Token token)
{
	m_token = std::make_unique<Token>(token);
}

std::ostream& operator<< (std::ostream& out, const Slot& slot)
{

}

bool operator== (const Slot& slot) const;
bool operator!= (const Slot& slot) const;