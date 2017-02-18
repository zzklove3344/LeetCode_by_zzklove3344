/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

#include<stdio.h>
#include<stdlib.h>


/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
	*returnSize = 2;
	int *index = (int *)malloc((*returnSize) * sizeof(int));
	index[0] = 1;
	index[1] = numbersSize;
	while (index[0] < index[1])
	{
		if ((numbers[index[0] - 1] + numbers[index[1] - 1]) == target)
			return index;
		else
		{
			if ((numbers[index[0] - 1] + numbers[index[1] - 1]) < target)
				++index[0];
			else
				--index[1];
		}
	}
	//NO answer
	index[0] = -1;
	index[1] = -1;
	return index;
}
