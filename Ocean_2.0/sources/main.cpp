#include <iostream>

#include "control_class.h"
#include "stone_class.h"
#include "seaweed_class.h"
#include "prey_male_class.h"
#include "prey_female_class.h"
#include "predator_male_class.h"
#include "predator_female_class.h"
#include "enumerations.h"

int main()
{
	Control& control = Control::Instance (30, 30);

	control.AddMoreObjects<Stone>(ObjectType::STONE, 20);

	control.AddMoreObjects<Seaweed>(ObjectType::SEAWEED, 40);

	control.AddMoreObjects<PreyMale>(ObjectType::PREY_MALE, 20);

	control.AddMoreObjects<PreyFemale>(ObjectType::PREY_FEMALE, 20);

	control.AddMoreObjects<PredatorMale>(ObjectType::PREDATOR_MALE, 10);
	
	control.AddMoreObjects<PredatorFemale>(ObjectType::PREDATOR_FEMALE, 10);

	control.Run(50);

	return 0;
}