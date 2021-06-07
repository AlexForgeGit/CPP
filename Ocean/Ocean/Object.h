#pragma once


class Object
{
public:
	Object(int = 0, char = 0, bool = false);
	virtual ~Object();
	void setLive(int);
	int getLive() const;
	void setSymbol(char);
	char getSymbol() const;
	void setCanMove(bool);
	bool getCanMove() const;
	virtual void setHunger(int) {};
	virtual int getHunger() const { return 0; };
	virtual void setReproduction(int) {};
	virtual int getReproduction() const { return 0; };
	void killMe();

    static int getCountObject();

private:
	int live;
	char symbol;
	bool canMove;

	static int countObject;
};