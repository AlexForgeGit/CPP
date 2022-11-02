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


void Fishes::Move(std::pair<int, int> coord)
{
	SetCommand( std::make_pair( Command::MOVE_ME, coord ) );
}

void Fishes::Eat(std::pair<int, int> coord)
{
	SetCommand( std::make_pair( Command::EAT_IT, coord ) );
}

void Fishes::Pairing(std::pair<int, int> coord)
{
	SetCommand( std::make_pair( Command::PAIRING, coord ) );
}

void Behavior()
{
	auto obj_type = GetMemory().find( ObjectType::EMPTY); 

	//If the fish sees an empty slot, set command move me
	if ( obj_type != GetMemory().end() )
	{
		SetCommand( std::make_pair( Command::MOVE_ME, obj_type->second ) );
	}
}

void Fishes::ActionRequest(Field& field)
{
	//Die old age check;
	Objects::ActionRequest(field);

	//Unless the fish died of old age, continue to live
	if( GetCommand().first == Command::INACTION )
	{
		//If the fish has not eaten for a long time, return command delete this object
		if (DieHunger())
			KillMe();
		
		else
			Behavior();
	}
}

void Fishes::Action(Command command)
{	
	//Aging age + 1; 
	Objects::Action(command);

	//Growing hunger
	SetHunger( ++hunger_ );

	//If hunger is quenched, set hunger 0
	if (command.first == Command::EAT_SUCCES)
		SetHunger(0);

	//If move completed, set new coordinates
	else if (command.first == Command::MOVE_SUCCES)
		SetCoord(command.second);
}
