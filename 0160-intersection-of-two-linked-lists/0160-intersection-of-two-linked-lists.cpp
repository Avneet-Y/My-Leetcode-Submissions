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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* head1 = headA;
        ListNode* head2 = headB;
        
        while(head1 != head2)
        {
            if(head1 == NULL)
                head1 = headA;
            else
                head1 = head1->next;
            
            if(head2 == NULL)
                head2 = headB;
            else
                head2 = head2->next;
        }
        return head1;
    }
};