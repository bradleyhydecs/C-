using namespace std;
#include <iostream>
#include <assert.h>

int  bsearch(int *arr, int start, int end, int target)
{
	if (arr[start] == target)
		return start;
	else if (start == end) 
		return -1;

	int mid = (start+end)/2;

	if (arr[mid] == target)
		return mid;
	else if (arr[mid] < target) 
		return bsearch(arr, mid+1, end, target);
	else
		return bsearch(arr, start, mid, target);
}

int main()
{
	int arr[10] = {2,6,7,9,13,18,19,21,29,67};

	assert(bsearch(arr,0,10,2) == 0);
	assert(bsearch(arr,0,10,67) == 9);
	assert(bsearch(arr,0,10,1) == -1);
	assert(bsearch(arr,0,10,100) == -1);
	assert(bsearch(arr,0,10,18) == 5);
	assert(bsearch(arr,0,10,29) == 8);
	assert(bsearch(arr,0,10,6) == 1);

	cout << "it works" << endl;
}