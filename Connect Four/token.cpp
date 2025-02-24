#include "token.h"

const Token::Type& Token::getType() const
{
	return m_type;
}

std::ostream& operator<< (std::ostream& out, const Token::Type& type)
{
	std::array<char, Token::max_types> names{ 'R', 'Y'};

	out << names[type];
	return out;
}

std::ostream& operator<< (std::ostream& out, const Token& token)
{
	out << token.getType();
	return out;
}

bool Token::operator== (const Token& token) const
{
	return m_type == token.m_type;
}

bool Token::operator!= (const Token& token) const
{
	return !(*this == token);
}

Token Token::createRed()
{
	return Token{ red };
}

Token Token::createYellow()
{
	return Token{ yellow };
}