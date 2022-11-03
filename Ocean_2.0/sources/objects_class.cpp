#include <random>

#include "objects_class.h"

void Objects::Wait()
{
	SetCommand( std::make_pair( Command::INACTION, GetCoord() ) );
}

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

void Objects::KillMe()
{
	SetCommand( std::make_pair( Command::KILL_ME, GetCoord() ) );
}

void Objects::ActionRequest(Field& field) 
{
	//If it`s time to die, return command delete this object
	if (DieOldAge())
		KillMe();
}

void Objects::Action(std::pair<Command, std::pair<int, int>> command)
{	
	//Aging age + 1; 
	SetAge( ++age_ ); 
}
