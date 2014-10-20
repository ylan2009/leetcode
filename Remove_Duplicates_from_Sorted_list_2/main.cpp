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
		ListNode *r = head;
		bool flag = false;
		while(q)
		{
			while(q && q->val == p->val)
			{
				p->next = q->next;
				delete q;
				q = p->next;
				flag = true;
			}

			if(flag)
			{
				if(p==head)
				{
					r = q;
					head = q;
				}else
					r->next = q;
				delete p;
			}else
				r = p;
			
			flag = false;

			if(!q || !q->next)
             	return head;
			p = q;
			q = q->next;

		}
		return head;
	}
	ListNode * deleteDuplicates_helper(ListNode *head){
		//使用了辅助的链表头，使得所有的情况归于一种
		ListNode *helper = new ListNode(0);
		helper->next = head;
		ListNode *pre = helper;
		ListNode *cur = head;
		while(cur)
		{
			while(cur->next && pre->next->val == cur->next->val)
				cur = cur->next;
			if(pre->next != cur)
				pre->next = cur->next;
			else
				pre = pre->next;
			cur = cur->next;
		}
		return helper->next;
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
	p = head;
	while(p)
	{
		cout<<p->val<<" ";
		p = p->next;
	}
	cout<<endl;
	head = s.deleteDuplicates(head);
	p = head;
    while(p)
    {
    	cout<<p->val<<" ";
    	p = p->next;
    }
	cout<<endl;
	return 0;
}
