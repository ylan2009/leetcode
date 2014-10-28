#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
		if(!head || !head->next) return head;
 		ListNode *helper = new ListNode(0);       
		helper->next = head;
		ListNode *t = helper, *s = helper, *r;
		for(; t->next && t->next->val < x; t = t->next,s=s->next);
		if(!t->next) return head; //全部节点值都小于x，不动链表
		while(s->next)
		{
			r = s->next->next;
			if(s->next->val < x)
			{
				s->next->next = t->next;
				t->next = s->next;
				s->next = r;
				t = t->next;
			}
			else
			{
				s = s->next;
			}
		}

		return helper->next;
    }
};

 int main()
 {
	srand((unsigned int)time(NULL));
 	ListNode *head = new ListNode(0);
 	ListNode *t = head;
 	cout<<t->val<<" ";
 	for(int i = 1; i < 20; i++)
 	{
 		t->next = new ListNode(rand()%10);
 		t = t->next;
 		cout<<t->val<<" ";
 	}
 	cout<<endl;
 	Solution s;
 	head = s.partition(head,-1);
 	t = head;
 	while(t)
 	{
 		cout<<t->val<<" ";
 		t = t->next;
 	}
 }
