#pragma once

#include "fishes_class.h"

class Gender : public virtual Fishes
{
public:

	Gender(GenderType gender_type) : gender_type_(gender_type) {};

	virtual ~Gender() {}
	
	
	void SetGender(GenderType gender_type) { gender_type_ = gender_type; }

	GenderType GetGenderType() { return gender_type_; }

private:

	GenderType gender_type_;

};
