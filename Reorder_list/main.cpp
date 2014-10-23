#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution{
public:
	ListNode* reverse(ListNode *head)
	{
		ListNode *s = head;
		ListNode *r = NULL;
		ListNode *t;
		while(s){
			t = s->next;
			s->next = r;
			r = s;
			s = t;
		}
		return r;
	}
	void reorderList(ListNode *head){
		if(!head || !head->next ||!head->next->next)
		  return;
		ListNode *first;
		ListNode *second;
		for(first=head,second=head;second && second->next;second=second->next->next,first=first->next);
		ListNode *hs = first->next;
		first->next = NULL;
		hs = reverse(hs);

		ListNode *t;
		first = head;
		second = hs;
		while(second)
		{
			t = second->next;
			second->next = first->next;
			first->next = second;
			first = first->next->next;
			second = t;
		}
	}
};

int main()
{
	ListNode *head = new ListNode(0);
	ListNode *t  = head;
	for(int i = 1; i < 21; i++,t=t->next)
	  t->next = new ListNode(i);
	t = head;
	while(t)
	{
	  cout<<t->val<<" ";
	  t = t->next;
	}
	cout<<endl;
	Solution s;
	s.reorderList(head);
	t = head;
	while(t)
	{
	  cout<<t->val<<" ";
	  t = t->next;
	}
	cout<<endl;
}
