#include "fishes_class.h"

bool Fishes::DieHunger()
{
	if (hunger_ >= Settings::DEATH_THRESHOLD_OF_HUNGER && !FlipCoin())
		return true;
	else 
		return false;
}


void Fishes::LookNorth(Field& field)
{
	auto temp_coord = GetCoord();
	temp_coord.first--;

	//If the Y (first) coordinates are out of bounds, move them to opposite side
	if (temp_coord.first < 0)
		{
			temp_coord.first = field.GetRowCount();
			temp_coord.first--;
		} 

	memory_.insert(std::make_pair(field.GetObjectType(temp_coord),  temp_coord));
}

void Fishes::LookEast(Field& field)
{
	auto temp_coord = GetCoord();
	temp_coord.second++;

	//If the X (second) coordinates are out of bounds, move them to opposite side
	if (temp_coord.second == field.GetColumnCount())
		temp_coord.second = 0;

	memory_.insert(std::make_pair(field.GetObjectType(temp_coord),  temp_coord));

}

void Fishes::LookSouth(Field& field)
{
	auto temp_coord = GetCoord();
	temp_coord.first++;

	//If the Y (first) coordinates are out of bounds, move them to opposite side
	if (temp_coord.first == field.GetRowCount())
		temp_coord.first = 0;

	memory_.insert(std::make_pair(field.GetObjectType(temp_coord),  temp_coord));
}
void Fishes::LookVest(Field& field)
{
	auto temp_coord = GetCoord();
	temp_coord.second--;

	//If the Y (second) coordinates are out of bounds, move them to opposite side
	if (temp_coord.second < 0)
		{
			temp_coord.second = field.GetColumnCount();
			temp_coord.second--;
		}
	memory_.insert(std::make_pair(field.GetObjectType(temp_coord),  temp_coord));
}

void Fishes::LookAround(Field& field)
{
	ClearMemory();

	LookNorth(field);

	LookEast(field);

	LookSouth(field);

	LookVest(field);
}


std::pair<Command, std::pair<int, int>> Fishes::Move(std::pair<int, int> coord)
{
	return std::make_pair( Command::MOVE_ME, coord);
}

std::pair<Command, std::pair<int, int>> Fishes::Eat(std::pair<int, int> coord)
{
	return std::make_pair( Command::EAT_IT, coord);
}

std::pair<Command, std::pair<int, int>> Fishes::Pairing(std::pair<int, int> coord)
{
	return std::make_pair( Command::PAIRING, coord);
}

std::pair<Command, std::pair<int, int>> Fishes::ActionRequest(Field& field)
{
	if( Objects::ActionRequest(field).first == Command::KILL_ME)
		return std::make_pair(Command::KILL_ME, GetCoord());
	else
	{
		SetHunger( ++hunger_ );

		//If the fish has not eaten for a long time, return command delete this object
		if (DieHunger())
			return std::make_pair(Command::KILL_ME, GetCoord());

		//Return command inaction
		return std::make_pair(Command::INACTION, GetCoord());
	}
}