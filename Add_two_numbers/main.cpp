#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution{
public:
	ListNode *addTwoNumber(ListNode *l1,ListNode *l2)
	{
		if(!l1 && !l2) return NULL;
		ListNode *t1 = l1, *t2 = l2;
		ListNode *result = new ListNode(0);
		ListNode *r = result;
		int a = 0;
		while(t1 && t2)	
		{
			r->next = new ListNode( (a + t1->val + t2->val) % 10);
			a = (a + t1->val + t2->val) / 10;

			t1 = t1->next;
			t2 = t2->next;	
			r = r->next;
		}
		if(a)
		  r->next = new ListNode(a);
		int flag = 0;
		while(t1)
		{
			r->next = new ListNode(flag ? t1->val:t1->val+a);
			t1 = t1->next;
			r = r->next;
			flag = 1;
		}
		flag = 0;
		while(t2)
		{
			r->next = new ListNode(flag ? t2->val:t2->val+a);
			t2 = t2->next;
			r = r->next;
			flag = 1;
		}
		return result->next;
	}
};

int main()
{
	ListNode *h1 = new ListNode(3);
	ListNode *t  = h1;
	for(int i = 2; i > 0; i--,t=t->next)
	  t->next = new ListNode(i);
	t = h1;
	while(t)
	{
	  cout<<t->val<<" ";
	  t = t->next;
	}
	cout<<endl;
	ListNode *h2 = new ListNode(9);
	h2->next = new ListNode(8);
	t = h2;
	while(t)
	{
		cout<<t->val<<" ";
		t = t->next;
	}
	cout<<endl;
	Solution s;
	ListNode *head = s.addTwoNumber(h1,h2);
	t = head;
	while(t)
	{
	  cout<<t->val<<" ";
	  t = t->next;
	}
	cout<<endl;
}

