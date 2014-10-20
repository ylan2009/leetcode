#include<iostream>
#include<vector>
#include<stack>
using namespace std;

typedef struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x),left(NULL),right(NULL){}
}link;

class Solution{
public:
	void preorderTraversal_rec(TreeNode *root){
		if(!root) return;
		cout<<root->val<<" ";
		preorderTraversal_rec(root->left);
		preorderTraversal_rec(root->right);	
	} 
	vector<int> preorderTraversal(TreeNode *root){
		vector<int> v;
		stack<TreeNode *>s;
		if(!root) return v;
		TreeNode *h = root;
		while(!s.empty() || h)
		{
			while(h)
			{
				v.push_back(h->val);
				s.push(h);
				h = h->left;
			}
			if(!s.empty())
			{
				h = s.top();
				s.pop();
				h = h->right;	
			}
		}
		return v;
	}

	vector<int> postorderTraversal(TreeNode *root){
		vector<int> v;
		stack<TreeNode *> s;
		TreeNode *pre = NULL;
		TreeNode *cur;
		s.push(root);
		while(!s.empty())
		{
			cur = s.top();
			if((!cur->left && !cur->right) || (pre && (pre==cur->left || pre==cur->right)))
			{
				v.push_back(cur->val);
				s.pop();
				pre = cur;
			}
			else
			{
				if(cur->right) s.push(cur->right);
				if(cur->left) s.push(cur->left);
			}
		}
		return v;
	}
};

TreeNode *createTree(int array[],int i,int n)
{
	if(i>=n) return NULL;
	TreeNode *t = new TreeNode(array[i]);
	t->left = createTree(array,2*i+1,n);
	t->right = createTree(array,2*i+2,n);
	return t;
}


int main()
{
	Solution s;
	TreeNode *root = NULL;
	int array[20];
	for(int i = 0; i < 21; i++)
		array[i] = i;
	root = createTree(array,0,21);	
	vector<int>	v;
	v = s.postorderTraversal(root);
	vector<int>::iterator iter = v.begin();
	for(;iter != v.end();iter++)
		cout<<*iter<<" ";
	cout<<endl;
}
