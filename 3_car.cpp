// bradley hyde
// bradleyhydecs@gmail.com
// z5063156@zmail.unsw.edu.au

#include <iostream>
#include "3_car.hpp"

// enum CAR_MODEL
// {
// 	TOYOTA, SUBARU, HYUNDAI
// };

// DEFAULT constructor
// delegates to my constructor
Car::Car() : Car{"Unknown", 4} 
{
	std::cout << "DEFAULT constructor" << std::endl;
}

// destructor
Car::~Car()
{
	num_objects_--;
	std::cout << "DELETING object" << std::endl;
}

// MY constructor
Car::Car(const std::string& m, unsigned int n = 2)
{
	manufacturer_ = m;
	num_seats_ = n;
	num_objects_++;
	std::cout << "MY constructor" << std::endl;
}

int Car::num_objects_ = 0;

const std::string& Car::getManufacturer() const
{
	return manufacturer_;
}

unsigned int Car::getNumSeats() const
{
	return num_seats_;
}

int Car::getNumObjects() 
{
	return num_objects_;
}

int main( )
{
	// STACK - automatically freed
	// Car car;

	// HEAP - muts manually free
	Car* car = new Car();

	std::cout << "My car is " << car->getNumSeats() << " seater of type: " << car->getManufacturer() << std::endl;

	delete car;

	return 0;
}