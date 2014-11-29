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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode *first, *second;
        ListNode *p = headA;
        for(;p->next;p=p->next);
        p->next = headA;
        first = headB;
        second = headB;
        while(second && second->next)
        {
            first = first->next;
            second = second->next->next;
            if(first==second) break;
        }
        if(!second ||!second->next) 
        {
            p->next = NULL;
            return NULL;
        }
        second = headB;
        for(;first != second;first=first->next,second=second->next);
        p->next = NULL;
        return first;

    }
};
