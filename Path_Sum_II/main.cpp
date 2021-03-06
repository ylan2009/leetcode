#include<iostream>
#include<vector>
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
	vector<vector<int> > pathSum(TreeNode *root, int sum){
		vector<vector<int> > set;
		vector<int> v;
		int result = 0;
		calculate(root,sum,result,v,set);	
		return set;
	}
	void calculate(TreeNode *root, int sum, int result, vector<int> v, vector<vector<int> > &set)
	{
		if(!root) return;
		result += root->val;
		v.push_back(root->val);
		if(!root->left && !root->right && result == sum) 
			set.push_back(v);
		calculate(root->left,sum,result,v,set);
		calculate(root->right,sum,result,v,set);
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
	vector<vector<int> > v = s.pathSum(root,14);
	for(vector<vector<int> >::iterator iter = v.begin();iter != v.end(); iter++)
	{	
		cout<<"[";
		for(vector<int>::iterator i = (*iter).begin(); i != (*iter).end(); i++)
			cout<<*i<<" ";
		cout<<"]"<<endl;
	}

}
