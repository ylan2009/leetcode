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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
		if(!head || !n) return head;
 		ListNode *helper = new ListNode(0);
		helper->next = head;
		ListNode *t = helper, *s = helper, *r = helper->next->next;
		for(; n && s; s=s->next,n--);
		for(; s->next && r && t->next; s=s->next,t=t->next,r=r->next);
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
 	head = s.removeNthFromEnd(head,3);
 	t = head;
 	while(t)
 	{
 		cout<<t->val<<" ";
 		t = t->next;
 	}
 }
