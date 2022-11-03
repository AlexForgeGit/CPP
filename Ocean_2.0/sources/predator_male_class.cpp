#include "predator_male_class.h"

void PredatorMale::Behavior()
{	
	auto obj_type = GetMemory().find( ObjectType::PREDATOR_FEMALE);

	//If the male sees the female , set command pairing
	if ( obj_type != GetMemory().end() )	
	{	
		SetCommand( std::make_pair( Command::PAIRING, obj_type->second ) );
	}
	else 
		Predator::Behavior();
}
