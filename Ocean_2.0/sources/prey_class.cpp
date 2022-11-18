#include <algorithm>

#include "prey_class.h"

void Prey::Behavior()
{	
	auto obj_type = std::find_if(GetMemory().begin(), GetMemory().end(), [] (const std::pair<ObjectType, std::pair<int, int>> &object) { return object.first == ObjectType::SEAWEED;});

	//If the prey saw seaweed, set command to it
	if ( obj_type != GetMemory().end() )	
	{	
		Eat(obj_type->second);
	}
	else 
		Fishes::Behavior();
}
