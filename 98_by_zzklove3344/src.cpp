 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

int getMax(struct TreeNode* root)
{
	struct TreeNode* temp = root;
	while (temp)
	{
		if (temp->right)
			temp = temp->right;
		else
			return temp->val;
	}
	return temp->val;
}

int getMin(struct TreeNode* root)
{
	struct TreeNode* temp = root;
	while (temp)
	{
		if (temp->left)
			temp = temp->left;
		else
			return temp->val;
	}
	return temp->val;
}


bool isValidBST(struct TreeNode* root) {
	int min = 0, max = 0;
	bool leftSubtree = true, rightSubtree = true, minFlag = false, maxFlag = false;
	if (root)
	{
		leftSubtree = isValidBST(root->left);
		rightSubtree = isValidBST(root->right);
		if (leftSubtree && rightSubtree)
		{
			if (root->left)
			{
				max = getMax(root->left);
				maxFlag = true;
			}
			if (root->right)
			{
				min = getMin(root->right);
				minFlag = true;
			}

			if ((!maxFlag || root->val > max) && (!minFlag || root->val < min))
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return true;
}