// bradley hyde
// bradleyhydecs@gmail.com
// Z5063156

#include <iostream>
#include <fstream>
#include "1_order_functions.h"

int main()
{
	int a, b, c;

	std::cin >> a;
	std::cin >> b;
	std::cin >> c;

	order3(&a,&b,&c);

	std::ofstream file;
	file.open("1_output.txt");
	file << a << std::endl;
	file << b << std::endl;
	file << c << std::endl;
	file.close();

	return 0;
}