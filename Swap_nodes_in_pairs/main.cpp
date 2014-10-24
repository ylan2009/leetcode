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
    ListNode *swapPairs(ListNode *head) {
        ListNode *helper = new ListNode(0);
        ListNode *r = helper, *s, *t;
        helper->next = head;
        while(r->next && r->next->next)
        {
            s = r->next;
            t = s->next->next;
            r->next = s->next;
            s->next->next = s;
            s->next = t;
            r = s;
        }
        return helper->next;
    }
};
