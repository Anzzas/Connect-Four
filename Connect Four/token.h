#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include <array>
#include <string>
#include <cassert>

class Token
{
public:

	enum Type
	{
		red,
		yellow,
		max_types,
	};

	Token() = delete;

	static Token createRed()
	{
		return Token{ red };
	}

	static Token createYellow()
	{
		return Token{ yellow };
	}

	const Type& getType() const;
	friend std::ostream& operator<< (std::ostream& out, const Type& type);
	friend std::ostream& operator<< (std::ostream& out, const Token& token);
	bool operator== (const Token& token) const;
	bool operator!= (const Token& token) const;

private:

	Token(Type type)
		: m_type{ type }
	{
	}

	const Type m_type;
};

#endif