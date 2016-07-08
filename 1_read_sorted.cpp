// bradley hyde
// bradleyhydecs@gmail.com
// Z5063156

#include <iostream>
#include <fstream>
#include "1_order_functions.h"

int main()
{
	unsigned int a, b, c;
	
	std::ifstream file ("1_output.txt");
	file >> a;
	file >> b;
	file >> c;

	order3(a,b,c);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	file.close();

	return 0;
}