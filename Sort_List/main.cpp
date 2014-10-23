#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL){}
};

class Solution{
public:
	
	ListNode* merger(ListNode *fh,ListNode *bh)
    {
    	ListNode *result = new ListNode(0);
    	ListNode *cur = result;
    	while(fh && bh)
    	{
    		if(fh->val<=bh->val)
    		{
    			cur->next = fh;
    			cur = cur->next;
    			fh = fh->next;
    		}
    		else
    		{
    			cur->next = bh;
    			cur = cur->next;
    			bh = bh->next;
    		}
    	}
		//for(ListNode *a = result->next;a;a = a->next)		
        //	cout<<a->val<<" ";
        //cout<<endl;


    	if(!fh)
    	{
    		cur->next = bh;
    	}
    	if(!bh)
    	{
    		cur->next = fh;
    	}
    
		//for(ListNode *a = result->next;a;a = a->next)
		//	cout<<a->val<<" ";
		//cout<<endl;
    	return result->next;
    }

	ListNode* mergersort(ListNode *head){
    	if(!head || !head->next) return head;
    	ListNode* first = head;
    	ListNode* second = head;
    	while(second->next && second->next->next)
    	{
    		first = first->next;
    		second = second->next->next;
    	}
    	second = first->next;
    	first->next = NULL;
    	first = head;
		//cout<<"first: ";
		//for(ListNode *a = first;a;a=a->next)
		//	cout<<a->val<<" ";
		//cout<<endl;
		//cout<<"second: ";
		//for(ListNode *b = second;b;b=b->next)
		//	cout<<b->val<<" ";
		//cout<<endl;
    	return merger(mergersort(first),mergersort(second));

    }
    
	ListNode *sortList(ListNode *head){
    	return mergersort(head);
    }


};

int main()
{
	ListNode *head = new ListNode(0);
	ListNode *t = head;
	for(int i = 20; i > 0; i--)
	{
		t->next = new ListNode(i);
		cout<<t->val<<" ";
		t = t->next;
	} 
	cout<<endl;
	Solution s;
	head = s.sortList(head);
	t = head;
	while(t)
	{
		cout<<t->val<<" ";
		t = t->next;
	}
	cout<<endl;
}
