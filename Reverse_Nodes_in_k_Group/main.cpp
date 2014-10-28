#include<iostream>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reverse(ListNode *head,ListNode *end)
	{
		ListNode *s = head, *t = NULL, *r;
		while(s!=end)
		{
			r = s->next;
			s->next = t;
			t = s;
			s = r;
		}
	}
    ListNode *reverseKGroup(ListNode *head, int k) {
		if(!k || k==1 || !head || !head->next) return head;//虽然去掉这句也accept，但实际上如果k=0时，不加上这句会出错。
    	ListNode *helper = new ListNode(0); 
		helper->next = head;
		ListNode *t = helper,*s, *r, *h;
		while(t->next)
		{
			s = t;
			h = t->next;
			for(int i = k; s && i; i--,s = s->next);
			if(!s) return helper->next;
			r = s->next;
			reverse(h,r);
			t->next = s;
			h->next = r;
			t = h;
		}
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
 	head = s.reverseKGroup(head,20);
 	t = head;
 	while(t)
 	{
 		cout<<t->val<<" ";
 		t = t->next;
 	}
 }
