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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* intersect = head;
        if(head == NULL || head->next == NULL)
            return NULL;
        
        while(slow != NULL && fast != NULL)
        {
            fast = fast->next;
            if(fast != NULL)
                fast = fast->next;
            slow = slow->next;
            if(slow == fast)
            {
                while(slow != intersect)
                {
                    slow = slow->next;
                    intersect = intersect->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};