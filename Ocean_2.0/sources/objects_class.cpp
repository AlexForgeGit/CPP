#include <random>

#include "objects_class.h"


bool Objects::FlipCoin()
{
	//Seed with a real random value
	std::random_device rand;

	//Setting the range from false to true, chance 50/50
	std::uniform_int_distribution<int> uniform_dist(false, true);

	return uniform_dist(rand);
}

//Check age and luck, if object old and unlucky returns the command to kill yourself
bool Objects::DieOldAge()
{
	if (age_ >= old_age_ && !FlipCoin())
		return true;
	else 
		return false;
}

std::pair<Command, std::pair<int, int>> Objects::ActionRequest(Field& field) 
{
	//Aging age + 1
	SetAge( ++age_ );

	//If it`s time to die, return command delete this object
	if (DieOldAge())
		return std::make_pair(Command::KILL_ME, GetCoord());

	//Return command inaction
	return std::make_pair(Command::INACTION, GetCoord());
}
