#include "Utils.h"
#include <iostream>

#define REVERSE_IN 10

/*
* Function reverses an array
* INPUT: nums (arr), size
*/
void reverse(int* nums, unsigned int size)
{
	int i = 0;
	int temp = 0;

	for (i = 0; i < size / 2; i++) // loop half way
	{
		// swap first and last
		temp = nums[size - i - 1];
		nums[size - i - 1] = nums[i];
		nums[i] = temp;
	}
}


/*
* Function takes in input for items in an array and returns 
* a reversed array.
* INPUT: None
* OUTPUT: reversed array
*/
int* reverse10()
{
	int i = 0;
	int arr[REVERSE_IN] = { 0 };

	for (i = 0; i < REVERSE_IN; i++)
	{
		std::cin >> arr[i];
	}
	
	reverse(arr, REVERSE_IN);

	return arr;
}
