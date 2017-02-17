#include "TreeNode.h"

class Solution {
public:
	int mySum(TreeNode* root, int t)
	{
		int leftSum = 0;
		int rightSum = 0;
		if (root == nullptr)
			return 0;
		else
		{
			t *= 10;
			t += root->val;
			if (root->left == nullptr&&root->right == nullptr)//Current node is leaf
			{
				int sum = 0;
				sum = t;
				return sum;
			}
			if (root->left)//Continue to visit other leaf
				leftSum = mySum(root->left, t);
			if (root->right)
				rightSum = mySum(root->right, t);
			return leftSum + rightSum;
		}
	}

	int sumNumbers(TreeNode* root)
	{
		int temp = 0;
		if (root)
			return  mySum(root, temp);
		else
			return 0;
	}

};
