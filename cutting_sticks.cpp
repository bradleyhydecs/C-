// bradley hyde
// bradleyhydecs@gmail.com
// z5063156@zmail.unsw.edu.au

#include <iostream>

void bubble_sort(int arr[], int n);

int main()
{
	int n;
	std::cin >> n;

	int arr[n];

	for (int i {0}; i < n; i++)
	{
		std::cin >> arr[i];
	}

	bubble_sort(arr, n);

	int prev {0};
	for (int i {0}; i < n; i++)
	{
		if (arr[i] != prev)
		{
			std::cout << (n-i) << std::endl;
		}
		prev = arr[i];
	}

    return 0;
}

// let's write a bubble sort for practice
// and for the lols
void bubble_sort(int arr[], int n)
{
	for (int i {0}; i < (n-1); i++)
	{
		for (int j {0}; j < (n-i)-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp {arr[j]};
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
