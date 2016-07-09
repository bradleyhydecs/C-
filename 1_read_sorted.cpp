// bradley hyde
// bradleyhydecs@gmail.com
// z5063156@zmail.unsw.edu.au

#include <iostream>
#include <fstream>
#include "1_cs6771.h"

int main()
{
	unsigned int a, b, c;

	std::ifstream file ("1_output.txt");
	file >> a;
	file >> b;
	file >> c;

	cs6771::order3(a,b,c);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	file.close();

	return 0;
}