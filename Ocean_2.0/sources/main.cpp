#include <iostream>

#include "control_class.h"
#include "factories.h"


int main()
{
	Control& control = Control::Instance (30, 30);

	StoneFactory stone_fac;
	SeaweedFactory seaweed_fac;
	PreyFactory prey_fac;
	PredatorFactory predator_fac;


	control.AddObjects(stone_fac, 40);
	control.AddObjects(seaweed_fac, 40);
	control.AddObjects(prey_fac, 40);
	control.AddObjects(predator_fac, 20);

	control.Run(50);



	return 0;
}
