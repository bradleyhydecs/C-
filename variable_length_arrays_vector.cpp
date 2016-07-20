// bradley hyde
// bradleyhydecs@gmail.com
// z5063156@zmail.unsw.edu.au

#include <iostream>
#include <vector>

int main()
{
	std::vector<std::vector<int> > v;
	unsigned int num_arrays, num_queries;

	std::cin >> num_arrays >> num_queries;

	// resize number of vectors in vector
	v.resize(num_arrays);

	for (unsigned int i{0}; i < num_arrays; i++)
	{
		unsigned int array_length;
		std::cin >> array_length;

		// resize number of elements in this vector
		v[i].resize(array_length);

		for (unsigned int j{0}; j < array_length; j++)
		{
			std::cin >> v[i][j];
		}
	}

	for (unsigned int i{0}; i < num_queries; i++)
	{
		unsigned int array;
		unsigned int index;
		std::cin >> array >> index;

		std::cout << v[array][index] << std::endl;
	}

	return 0;
}