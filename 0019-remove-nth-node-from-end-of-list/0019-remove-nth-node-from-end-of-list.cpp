/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        
        while(temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        if(count == 0)
            return NULL;
        if(count == n)
            return head->next;
        temp = head;
        int target = count-n;
        count = 0;
        while(temp != NULL)
        {
            count++;
            if(target == count)
                temp->next = temp->next->next;
            temp = temp->next;
        }        
        return head;
    }
};