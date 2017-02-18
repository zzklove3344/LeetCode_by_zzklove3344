#include<stdlib.h>
#include<stdio.h>

typedef struct numArray {
	int start;
	int end;
	int sum;
	struct numArray *left;
	struct numArray *right;
} NumArray;

NumArray* buildTree(int *nums, int start, int end)
{
	NumArray* temp = (NumArray*)malloc(sizeof(NumArray));
	if (start == end)
	{
		temp->sum = nums[start];
		temp->start = start;
		temp->end = end;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	else
	{
		int mid = start + (end - start) / 2;
		temp->start = start;
		temp->end = end;
		temp->left = buildTree(nums, start, mid);
		temp->right = buildTree(nums, mid + 1, end);
		temp->sum = temp->left->sum + temp->right->sum;
		return temp;
	}
}

NumArray* numArrayCreate(int* nums, int numsSize) {
	return buildTree(nums, 0, numsSize - 1);
}

int updateTree(NumArray* obj, int i, int val)
{
	int diff = 0;
	if ((obj->start == i) && (obj->end == i))
	{
		diff = val - obj->sum;
		obj->sum = val;
		return diff;
	}
	else
	{
		int mid = (obj->start + obj->end) / 2;
		if (i <= mid)
			diff = updateTree(obj->left, i, val);
		else
			diff = updateTree(obj->right, i, val);
	}
	obj->sum += diff;
	return diff;
}


void numArrayUpdate(NumArray* obj, int i, int val) {
	updateTree(obj, i, val);
}

int queryTree(NumArray* obj, int i, int j)
{
	//if (obj == nullptr)
	//	return 0;
	if ((obj->start == i) && (obj->end == j))
		return obj->sum;
	else
	{
		int mid = (obj->start + obj->end) / 2;
		if (j <= mid)
			return queryTree(obj->left, i, j);
		else if (i > mid)
			return queryTree(obj->right, i, j);
		else
			return queryTree(obj->left, i, mid) + queryTree(obj->right, mid + 1, j);
	}
}


int numArraySumRange(NumArray* obj, int i, int j) {
	return queryTree(obj, i, j);
}

void freeTree(NumArray* obj)
{
	if (obj->start == obj->end)
		free(obj);

	else
	{
		freeTree(obj->left);
		freeTree(obj->right);
		free(obj);
	}
}

void numArrayFree(NumArray* obj) {
	freeTree(obj);
}



int main()
{
	int nums[3] = { 1,3,5 };
	int size = 3;
	NumArray* t1 = numArrayCreate(nums, size);
	int i1 = numArraySumRange(t1, 0, 2);
	printf_s("%d\n", i1);
	numArrayUpdate(t1, 1, 2);
	int i2 = numArraySumRange(t1, 0, 2);
	printf_s("%d\n", i2);

	numArrayFree(t1);
	return 0;
}

/**
* Your NumArray struct will be instantiated and called as such:
* struct NumArray* obj = numArrayCreate(nums, numsSize);
* numArrayUpdate(obj, i, val);
* int param_2 = numArraySumRange(obj, i, j);
* numArrayFree(obj);
*/
