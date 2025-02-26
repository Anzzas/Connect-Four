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
	m_state = filled;
}

std::ostream& operator<< (std::ostream& out, const Slot::State& state)
{
	std::array<std::string, Slot::max_states> words{ "empty", "filled" };

	out << words[state];
	return out;
}

std::ostream& operator<< (std::ostream& out, const Slot& slot)
{
	out << "[";

	if (slot.m_token.get())
		out << *slot.m_token.get();

	else
		out << " ";

	out << "]";
	return out;
}

bool Slot::operator== (const Slot& slot) const
{
	if (m_token.get() && slot.m_token.get())
		return  *m_token.get() == *slot.m_token.get();

	return false;
}

bool Slot::operator!= (const Slot& slot) const
{
		return !(*this == slot);
}

bool Slot::isEmpty() const
{
	return m_state == empty && m_token == nullptr;
}

void Slot::clear()
{
	m_state = empty;
	m_token = nullptr;
}