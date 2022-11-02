#include "female_class.h"

	
void Female::Action(Command command)
{
	switch( command.first )
	{
		//If pairing is successful
		case Command::PAIRING_SUCCES:

			//Conception
			SetGestation( GetGestation() + 1 );

			//Aging age + 1, Growing hunger, check eat, check move
			Fishes::Action(command);
			break;

		case Command::CHILD_BIRTH_SUCCES:

			SetGestation(0);

			Fishes::Action(command);
			break;

		default:
			if ( GetGestation() > 0 )
			{
				//Time gestation + 1
				SetGestation( GetGestation() + 1 );

				Fishes::Action(command)
				break;
			}
			else
				Fishes::Action(command);

			break;
	}
}
