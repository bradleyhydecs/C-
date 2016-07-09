// bradley hyde
// bradleyhydecs@gmail.com
// z5063156@zmail.unsw.edu.au


#include <iostream>
#include <fstream>
#include "1_cs6771.h"

int main()
{
	int a, b, c;

	std::cin >> a;
	std::cin >> b;
	std::cin >> c;

	cs6771::order3(&a,&b,&c);

	std::ofstream file;
	file.open("1_output.txt");
	file << a << std::endl;
	file << b << std::endl;
	file << c << std::endl;
	file.close();

	return 0;
}