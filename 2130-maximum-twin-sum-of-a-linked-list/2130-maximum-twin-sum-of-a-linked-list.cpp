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
    ListNode *reverse(ListNode *head)
    {
        if(head == NULL)
            return head;
        ListNode *prev = NULL;
        ListNode *forward = NULL;
        ListNode *curr = head;
        while(curr!=NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
    int pairSum(ListNode* head) {
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = reverse(slow);
        int maxi = INT_MIN;
         
        while(slow != NULL)
        {
            maxi = max(maxi, slow->val + head->val);
            slow = slow->next;
            head = head->next;    
        }
        return maxi;
    }
};