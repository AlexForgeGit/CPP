#pragma once

class Object
{
public:
	Object(int = 0, char = 0);
	virtual ~Object();
	void setLive(int);
	int getLive() const;
	void setSymbol(char);
	char getSymbol() const;

private:
	int live;
	char symbol;
};