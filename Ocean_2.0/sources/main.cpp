#include <iostream>

#include "control_class.h"

int main()
{
	Control& control = Control::Instance (50, 75);

	control.AddMoreObjects(ObjectType::STONE, 50);

	control.AddMoreObjects(ObjectType::SEAWEED, 50);

	control.AddMoreObjects(ObjectType::PREY_MALE, 50);

	control.AddMoreObjects(ObjectType::PREY_FEMALE, 50);

	control.AddMoreObjects(ObjectType::PREDATOR_MALE, 50);
	
	control.AddMoreObjects(ObjectType::PREDATOR_FEMALE, 50);

	control.Run(50);

	return 0;
}