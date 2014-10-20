#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
	//ʹ�ÿ���ָ�룬��ָ��һ���ƶ�1���ڵ㣬��ָ��һ���ƶ�2���ڵ�
	//����ָ���ƶ��Ľڵ�����x������������ʱ����(2*x)%(�����еĽڵ���Ŀ) = x%(�����еĽڵ���Ŀ)
	//���������еĽڵ���������������ż�����ܿ����ҵ�һ��xʹ���������
	//���ж�true������ֻ��Ҫ���Ƿ���ps==pf����
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
