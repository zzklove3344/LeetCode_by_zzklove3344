void myReverse(int* nums, int left, int right)
{
	int temp = 0;
	while (left<right)
	{
		temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;
		++left;
		--right;
	}
}


void rotate(int* nums, int numsSize, int k)
{
	if (numsSize == 0)
		return;
	k = k % numsSize;
	myReverse(nums, 0, numsSize - 1 - k);
	myReverse(nums, numsSize - k, numsSize - 1);
	myReverse(nums, 0, numsSize - 1);
}
