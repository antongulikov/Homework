#pragma once

class Calculator
{
	
public:
	/// Method wich calculate expression
	int calculate(const char *message);
	
private:
	/// Method checks whether a character to digits.
	bool nums(char ch);
	/// Method checks whether a character to signs.
	bool signs(char ch);
	/// Method which calc operation's priority .
	int priority(char ch);
	/// Method checks whether a characer is bad.
	bool bad(char ch);
	/// Method checks whether a character to brackets.
	bool brackets(char ch);
	/// Method which transofrm expression to Polish Notation.
	char *toPolish(const char *message);
	/// Method which calculate result.
	int calcResult(char *polish);
};

