#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL){}
};

void merger(ListNode*,ListNode*,ListNode*);

void mergersort(ListNode *start,ListNode *end){
	if(!start || !start->next) return;
	ListNode *mid = start;
	for(ListNode *p = start; p!=end; p = p->next)
	  mid = mid->next; 
	mergersort(start,mid);
	mergersort(mid,end);
	merger(start,mid,end);

}
void merger(ListNode *fh,ListNode *bh,ListNode *end)
{
	ListNode *fhpr = new ListNode(0);
	ListNode *bhpr = new ListNode(0);
	fhpr->next = fh;
	bhpr->next = bh;
	ListNode *p = fhpr;
	ListNode *q = bhpr;
	ListNode *t;
	ListNode *s = bhpr->next;
	while(p->next!=bh && q->next!=end)
	{
		s = q->next;
		while(p->next->val >= q->next->val)
		{
			q = q->next;
		}
		
		bhpr->next = q->next;
		q->next = p->next;
		p->next = s;
		
		p = q->next;
		q = bhpr;
	}
	if(p->next == bh)
	  p->next = bhpr->next;
}
class Solution{
public:
	ListNode *sortList(ListNode *head){
		mergersort(head,NULL);
	}
};

int main()
{
	ListNode *head = new ListNode(0);
	ListNode *t = head;
	for(int i = 20; i > 0; i++)
	{
		t->next = new ListNode(i);
		t = t->next;
	} 
	Solution s;
	s.sortList(head);
	t = head;
	while(t)
	{
		cout<<t->val<<" ";
		t = t->next;
	}
	cout<<endl;
}
