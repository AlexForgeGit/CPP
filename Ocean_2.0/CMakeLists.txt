cmake_minimum_required(VERSION 3.1)

project(Ocean_2.0)


include_directories(headers)


add_executable(Ocean sources/field_class.cpp sources/objects_class.cpp sources/fishes_class.cpp
					 sources/prey_class.cpp sources/prey_male_class.cpp sources/prey_female_class.cpp 
					 sources/predator_class.cpp sources/predator_male_class.cpp sources/predator_female_class.cpp 
					 sources/control_class.cpp sources/main.cpp) 

