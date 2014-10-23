#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};


void printList(ListNode *head)
{
	ListNode *t  = head;
	while(t)
	{
		cout<<t->val<<" ";
		t = t->next;
	}
	cout<<endl;
}


class Solution{
public:
	ListNode *insertionSortList(ListNode *head)
	{
		ListNode *result = new ListNode(0);
		ListNode *cur = result;
		ListNode *t = head;
		ListNode *s;
		while(t)
		{
			s = t->next;
			while(cur->next && t->val > cur->next->val)	
				cur = cur->next;
			t->next = cur->next;
			cur->next = t;
			t = s;
			cur = result;
			//printList(cur->next);
		}
		return result->next;
		

	}
};

int main()
{
	Solution s;
	ListNode *head = new ListNode(0);
	ListNode *t = head;
	srand((unsigned)time(NULL));
	for(int i = 0; i < 10; i++)
	{
		t->next = new ListNode(rand()%100);	
		t = t->next;

	}
	printList(head->next);
	head->next = s.insertionSortList(head->next);
	printList(head->next);
}
