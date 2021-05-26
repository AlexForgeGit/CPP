#pragma once
#include "Object.h"

class Stone : public Object
{
public:
	Stone();
	~Stone();
	void setLive(int);
	void printMe();
private:
	int live;
};