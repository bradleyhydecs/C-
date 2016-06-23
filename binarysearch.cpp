using namespace std;
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int  bsearch(int *arr, int start, int end, int target)
{
	printf("start: %d and end %d \n", start, end);
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
		return bsearch(arr, start, mid-1, target);
}

int main()
{
	int arr[10] = {2,6,7,9,13,18,19,21,29,67};
    int location = bsearch(arr,0,10,2);
    printf("----------->location: %d \n", location);
    int location2 = bsearch(arr,0,10,67);
    printf("----------->location: %d \n", location2);
    // int location3 = bsearch(arr,0,10,1);
    // printf("----------->location: %d \n", location3);
    int location4 = bsearch(arr,0,10,77);
    printf("----------->location: %d \n", location4);
    int location5 = bsearch(arr,0,10,6);
    printf("----------->location: %d \n", location5);
    int location6 = bsearch(arr,0,10,18);
    printf("----------->location: %d \n", location6);
}