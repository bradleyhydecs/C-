using namespace std;
#include <iostream>
#include <assert.h>

// merge to two sub arrays in sorted order
int  merge(int *arr, int start, int mid, int end)
{
	int s = start;
	int i = start;
	int m = mid + 1;
	int k;
	int temp[10];

	// put values into temp array in sorted order
	while ((s <= mid) && (m <= end))
	{
		if (arr[s] <= arr[m])
		{
			temp[i] = arr[s];
			s++;
		}
		else
		{
			temp[i] = arr[m];
			m++;
		}
		i++;
	}

	// fill in the remaining values
	if (s > mid)
	{
		for(k = m; k <= end; k++)
		{
			temp[i] = arr[k];
			i++;
		}
	}
	else
	{
		for(k = s; k <= mid; k++)
		{
			temp[i] = arr[k];
			i++;
		}
	}

	// replace the old array with the new sorted array
	for(i = start; i <= end; i++)
	{
		arr[i] = temp[i];
	}
}

// partition array for merge process
int  mergesort(int *arr, int start, int end)
{
	if (start < end)
	{
		int mid = (start+end) / 2;
		mergesort(arr, start, mid);
		mergesort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}

int main()
{
	int arr[10] = {29,2,7,1,13,11,19,21,2,67};

	mergesort(arr,0,9);

	printf("[%d %d %d %d %d %d %d %d %d %d]", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9] );
}