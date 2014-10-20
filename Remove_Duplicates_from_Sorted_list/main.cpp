#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution{
public:
	ListNode *deleteDuplicates(ListNode *head){
		if(!head || !head->next)
			return head;
		ListNode *p = head;
		ListNode *q = head->next;
		while(q)
		{
			while(q->val == p->val)
			{
				p->next = q->next;
				delete q;
				q = p->next;
				if(!q)
					return head;
			}
			p = p->next;
			q = q->next;
		}
		return head;
	}
};
int main()
{
	Solution s;
	ListNode *head = new ListNode(0);
	ListNode *p = head;
	int i;
	for(i = 1; i < 9;i++)
	{
		p->next = new ListNode(i);
		p = p->next;
		p->next = new ListNode(i);
		p = p->next;
	}
	p->next = new ListNode(i);
	p = p->next;
	p->next = NULL;

	ListNode *head2 = new ListNode(10);
	head2->next = new ListNode(10);
	head2->next->next = NULL;
	p = head2;
	while(p)
	{
		cout<<p->val<<" ";
		p = p->next;
	}
	cout<<endl;
	head2 = s.deleteDuplicates(head2);
	p = head2;
    while(p)
    {
    	cout<<p->val<<" ";
    	p = p->next;
    }
	cout<<endl;
	return 0;
}
