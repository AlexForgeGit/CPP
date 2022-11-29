#include <algorithm>

#include "predator_class.h"


void Predator::Behavior()
{	
	auto obj_type = std::find_if(GetMemory().begin(), GetMemory().end(), [] ( std::pair<ObjectType, std::pair< int, int >> object) 
		{ return object.first == ObjectType::PREY_MALE || object.first == ObjectType::PREY_FEMALE; });

	//If the prey saw seaweed, set command to it
	if ( obj_type != GetMemory().end() )	
	{	
		GetLogs().WriteString("Predator["+ std::to_string(GetCoord().first)+ "." + std::to_string(GetCoord().second) + "] eat prey["
		+ std::to_string(obj_type->second.first)+ "." + std::to_string(obj_type->second.second) + "]" ); 
		Eat(obj_type->second);
	}
	else 
		Fishes::Behavior();
}
