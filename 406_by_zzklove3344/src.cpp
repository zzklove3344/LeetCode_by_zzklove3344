/**
* Return an array of arrays of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
#include<stdio.h>
#include<stdlib.h>

/*struct pair
{
	int position;
	int value;
};


void exchange(struct pair* x, struct pair* y)
{
	struct pair temp;
	temp.position = x->position;
	temp.value = x->value;
	x->position = y->position;
	x->value = y->value;
	y->position = temp.position;
	y->value = temp.value;
}


int partition(struct pair* array, int left, int right)
{
	int x = array[right].value, i = left - 1, j = left;
	for (;j <= right - 1;++j)
	{
		if (array[j].value <= x)
		{
			++i;
			exchange(array + i, array + j);
		}
	}
	exchange(array + i + 1, array + right);
	return i + 1;
}


void quickSort(struct pair* array, int left, int right)
{
	int q = 0;
	if (left < right)
	{
		q = partition(array, left, right);
		quickSort(array, left, q - 1);
		quickSort(array, q + 1, right);
	}
}*/





int** reconstructQueue(int** people, int peopleRowSize, int peopleColSize, int* returnSize)
{
	//Store the insert order
	//struct pair* insertOrder = (struct pair*)malloc(peopleRowSize * sizeof(struct pair));
	int i = 0, j = 0, k=0;
	int* temp = (int *)malloc(peopleRowSize * sizeof(int));
	int tempIndex = 0;
	int** result= (int **)malloc(peopleRowSize * sizeof(int **));
	int *s = (int *)malloc(peopleRowSize*peopleColSize * sizeof(int));
	for (int i = 0;i < peopleRowSize;++i)
		result[i] = s + i*peopleColSize;
	*returnSize = peopleRowSize;
	/*for(i=0;i<peopleRowSize;++i)
	{
		for (j = 0;j < peopleColSize;++j)
			printf_s("%d   ", people[i][j]);
		printf_s("\n");
	}*/

	/*for (i = 0;i < peopleRowSize;++i)
	{
		insertOrder[i].position = i;
		insertOrder[i].value = people[i][1];
	}*/
/*	for (i = 0;i<peopleRowSize;++i)
	{ 
		printf_s("%d   %d\n", insertOrder[i].position, insertOrder[i].value);
	}
	*///QuickSort
	//quickSort(insertOrder, 0, peopleRowSize - 1);

	//printf_s("\n");
	/*for (i = 0;i<peopleRowSize;++i)
	{
			printf_s("%d   %d\n", insertOrder[i].position,insertOrder[i].value);
	}*/

	//printf_s("\n");

	/*for (i = 0;i < peopleRowSize;++i)
	{
		int t = insertOrder[i].value;
		for (j = 0;j < tempIndex;++j)
		{
			printf_s("比较数%d    %d\n", people[insertOrder[i].position][0], people[temp[j]][0]);
			if (people[insertOrder[i].position][0] <= people[temp[j]][0])
			{
				--t;
				if (t == -1)
				{
					j--;
					break;
				}
			}
		}
		if (tempIndex == 0)
		{
			temp[tempIndex] = insertOrder[i].position;
			++tempIndex;
		}
		else
		{
			if (j == tempIndex)
				temp[tempIndex++] = insertOrder[i].position;
			else
			{
				for (k = tempIndex - 1;k > j;--k)
					temp[k + 1] = temp[k];
				temp[j + 1] = insertOrder[i].position;
				++tempIndex;
			}
		}
		for (k = 0;k < tempIndex;++k)
		{
			printf_s("当前temp数组的情况：%d   %d\n", temp[k], tempIndex);
		}
		printf_s("\n");
		
		//pull back
	}

	for (k = 0;k < peopleRowSize;++k)
	{
		printf_s("%d ", temp[k]);
	}*/

	/*for (k = 0;k < tempIndex;++k)
	{
		result[k][0] = people[temp[k]][0];
		result[k][1] = people[temp[k]][1];
	}*/

	free(insertOrder);
	return people;
}


int main(void)
{
	int row = 6, col = 2;
	int returnSize = 0;
	int** people = (int **)malloc(row*sizeof(int **));
	int *s = (int *)malloc(row*col * sizeof(int));
	for (int i = 0;i < row;++i)
		people[i] = s + i*col;
	people[0][0] = 7, people[0][1] = 0;
	people[1][0] = 4, people[1][1] = 4;
	people[2][0] = 7, people[2][1] = 1;
	people[3][0] = 5, people[3][1] = 0;
	people[4][0] = 6, people[4][1] = 1;
	people[5][0] = 5, people[5][1] = 2;

	int **result = reconstructQueue(people, row, col, &returnSize);

	return 0;
	//{ {7, 0 }, { 4,4 }, { 7,1 }, { 5,0 }, { 6,1 }, { 5,2 } }
}


