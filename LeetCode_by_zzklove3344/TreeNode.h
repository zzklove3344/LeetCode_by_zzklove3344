#ifndef TREENODE_H
#define TREENODE_H

//Definition for a binary tree node.
struct TreeNode {
	int val;//from 0 to 9
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};


#endif // !TREENODE_H

