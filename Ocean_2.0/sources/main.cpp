#include <iostream>

#include "control_class.h"
#include "stone_class.h"
#include "seaweed_class.h"
#include "prey_male_class.h"
#include "prey_female_class.h"
#include "predator_male_class.h"
#include "predator_female_class.h"
#include "enumerations.h"

#include "logs_class.h"

int main()
{
	Control& control = Control::Instance (30, 30);

	control.AddMoreObjects<Stone>(40);

	control.AddMoreObjects<Seaweed>(40);

	control.AddMoreObjects<PreyMale>(20);

	control.AddMoreObjects<PreyFemale>(20);

	control.AddMoreObjects<PredatorMale>(10);
	
	control.AddMoreObjects<PredatorFemale>(10);

	control.Run(50);



	return 0;
}