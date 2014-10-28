#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution{
public:
	void reverse(ListNode *head,ListNode *end)
	{
		ListNode *s = head, *r;
		ListNode *t = NULL;
		while(s!=end)
		{
			r = s->next;
			s->next = t;
			t = s;
			s = r;
		}
		
	}
	ListNode *reverseBetween(ListNode *head,int m,int n){
		if(!head || !head->next || m==n) return head;
		ListNode *helper = new ListNode(0);
		helper->next = head;
		ListNode *t = helper, *r = helper, *s;
		for(int i = 0; i < m-1 && t; t=t->next,i++);
		for(int i = 0; i < n && r; r=r->next,i++);
		s = r->next;
		reverse(t->next,s);
		t->next->next = s;
		t->next = r;
		return helper->next;
	}
};
int main()
{
	ListNode *head = new ListNode(0);
	ListNode *t = head;
	cout<<t->val<<" ";
	for(int i = 1; i < 10; i++)
	{
		t->next = new ListNode(i);
		t = t->next;
		cout<<t->val<<" ";
	}
	cout<<endl;
	Solution s;
	s.reverseBetween(head,1,1);
	t = head;
	while(t)
	{
		cout<<t->val<<" ";
		t = t->next;
	}
}
