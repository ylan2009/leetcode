//Definition for singly-linked list.
#include<iostream>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *result = new ListNode(0);
        ListNode *cur = result;
        ListNode *t1 = l1, *t2 = l2;
        while(t1 && t2)
        {
            if(t1->val < t2->val)
            {
                cur->next = t1;
                t1 = t1->next;
                cur->next->next = NULL;
                cur = cur->next;
            }
            else
            {
                cur->next = t2;
                t2 = t2->next;
                cur->next->next = NULL;
                cur = cur->next;
            }
        }
        if(t1)
        {
            cur->next = t1;
        }
        if(t2)
        {
            cur->next = t2;
        }
        return result->next;
    }
};
int main()
{
	ListNode *h1 = new ListNode(1);
	ListNode *h2 = new ListNode(5);
	ListNode *t1 = h1;
	ListNode *t2 = h2;
	for(int i = 2; i < 5; i++)
	{
		t1->next = new ListNode(i);	
		t1 = t1->next;
		cout<<t1->val<<" ";
	}
	cout<<endl;
	for(int i = 6; i < 9; i++)
    {
    	t2->next = new ListNode(i);	
    	t2 = t2->next;
		cout<<t2->val<<" ";
    }
	cout<<endl;
	Solution s;
	ListNode *h = s.mergeTwoLists(h1,h2);
	ListNode *t = h;
	while(t)
	{
		cout<<t->val<<" ";
		t = t->next;
	}
	cout<<endl;
}

