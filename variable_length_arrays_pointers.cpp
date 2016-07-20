// bradley hyde
// bradleyhydecs@gmail.com
// z5063156@zmail.unsw.edu.au

#include <iostream>
#include <vector>

int main()
{
	unsigned int num_arrays, num_queries;
	std::cin >> num_arrays >> num_queries;
	
        // creates an array of pointers
	unsigned int** v {new unsigned int*[num_arrays]};

	for (unsigned int i {0}; i < num_arrays; i++)
	{
		unsigned int array_length;
		std::cin >> array_length;

		v[i] = new unsigned int[array_length];

		for (unsigned int j {0}; j < array_length; j++)
		{
			std::cin >> v[i][j];
		}
	}

	for (unsigned int i {0}; i < num_queries; i++)
	{
		unsigned int array, index;
		std::cin >> array >> index;

		std::cout << v[array][index] << std::endl;
	}

	return 0;
}
