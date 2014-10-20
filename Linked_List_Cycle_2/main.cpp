#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
	//使用快慢指针，慢指针一次移动1个节点，快指针一次移动2个节点
	//设慢指针移动的节点数是x，则当两者相遇时，有(2*x)%(链表中的节点数目) = x%(链表中的节点数目)
	//不管链表中的节点数量是奇数还是偶数，总可以找到一个x使得两者相等
	//故判断true的条件只需要看是否有ps==pf即可
	bool hasCycle(ListNode *head){
		ListNode *ps = head, *pf = head;
		if (!head || !head->next)
			return false;
		while(pf && pf->next)
		{
			pf = pf->next->next;
			ps = ps->next;
			if(ps==pf)
				return true;
		}
		return false;
	}
	ListNode *detectCycle(ListNode *head){
		ListNode *ps = head, *pf = head;
		if(!head || !head->next)
			return NULL;
		while(pf && pf->next)
		{
			pf = pf->next->next;
			ps = ps->next;
			if(ps == pf)
				break;
		}
		if(pf && pf->next)
		{
			ps = head;
			while(ps!=pf)
			{
				ps = ps->next;
				pf = pf->next;
			}
			return ps;
		}
		return NULL;
	}

};
int main(){
	Solution s;
	ListNode *head = new ListNode(0);
	ListNode *p = head;
	ListNode *q = NULL;
	for(int i = 1; i < 11; i++)
	{
		p->next = new ListNode(i);
		p = p->next;
		if(i == 8)
			q = p;
	}
	p->next = q;
	cout<<s.detectCycle(head)->val<<endl;
}
