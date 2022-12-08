#pragma once

#include <random>
#include <memory>

#include "stone_class.h"
#include "objects_class.h"
#include "seaweed_class.h"
#include "prey_male_class.h"
#include "prey_female_class.h"
#include "predator_male_class.h"
#include "predator_female_class.h"

class ObjectsFactory
{
public:
	virtual std::shared_ptr<Objects> CreateObject(std::pair<int, int> coord) = 0;

	int FlipCoin(){
		std::random_device rand;
		std::uniform_int_distribution<int> uniform_dist(false, true);
		return uniform_dist(rand);
	}
};

class StoneFactory : public ObjectsFactory
{
public:
	virtual std::shared_ptr<Objects> CreateObject(std::pair<int, int> coord) {
		return std::make_shared<Stone>(coord);
	}
};

class SeaweedFactory : public ObjectsFactory
{
public:
	virtual std::shared_ptr<Objects> CreateObject(std::pair<int, int> coord) {
		return std::make_shared<Seaweed>(coord);
	}
};

class PreyFactory : public ObjectsFactory
{
public:
	virtual std::shared_ptr<Objects> CreateObject(std::pair<int, int> coord) {
		if(FlipCoin()) 
			return std::make_shared<PreyMale>(coord);
		else
			return std::make_shared<PreyFemale>(coord);
	}
};

class PredatorFactory : public ObjectsFactory
{
public:
	virtual std::shared_ptr<Objects> CreateObject(std::pair<int, int> coord) {
		if(FlipCoin()) 
			return std::make_shared<PredatorMale>(coord);
		else
			return std::make_shared<PredatorFemale>(coord);
	}
};
