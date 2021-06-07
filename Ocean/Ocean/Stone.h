#pragma once
#include "Object.h"

class Stone : public Object
{
public:
	Stone(int = 0, char = 0, bool = false);
	~Stone();

	static int getCountStone();

private:
	static int countStone;
};