#include "prey_female_class.h"


void PreyFemale::Behavior()
{	
	auto obj_type = GetMemory().find( ObjectType::EMPTY);

	//When it`s time to give birth, set command childbirth
	if ( (GetGestation() >= MAX_DESTATIONAL_AGE) && obj_type != GetMemory().end() )	
	{	
		SetCommand( ChildBirth( obj_type->second ) );
	}
	else 
		Prey::Behavior();
}
