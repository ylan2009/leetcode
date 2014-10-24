/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head || !k) return head; //k=0�����Ҳ�����������ѭ���У�������ʾд���������Ч��
        ListNode *f = head, *s = head;
        for(;s->next;s=s->next);
        s->next = head;
        for(s=head;k>0;k--,s=s->next);
        for(;s->next!=head;f=f->next,s=s->next);
        ListNode *result = f->next;
        f->next = NULL;
        return result;
            
    }
};
