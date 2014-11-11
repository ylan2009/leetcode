#include<iostream>
using namespace std;
// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
	bool hasPathSum(TreeNode *root, int sum){
		int result = 0;
		return calculate(root,sum,result);	
	}
	bool calculate(TreeNode *root, int sum, int result)
	{
		if(!root) return false;
		result += root->val;
		if(!root->left && !root->right) return result == sum;
		if(calculate(root->left,sum,result) || calculate(root->right,sum,result))
			return true;
		else
			return false;
	}
};

TreeNode *createTree(int val[],int i,int n)
{
	if(i>=n) return NULL;
	TreeNode *root = new TreeNode(val[i]);
	root->left = createTree(val,i*2+1,n);
	root->right = createTree(val,i*2+2,n);
	return root;
}
int main()
{
	TreeNode *root;
	int a[15];
	for(int i = 0; i < 15; i++)
		a[i] = i;
	root = createTree(a,0,15);	
	Solution s;
	cout<<s.hasPathSum(root,);
}
