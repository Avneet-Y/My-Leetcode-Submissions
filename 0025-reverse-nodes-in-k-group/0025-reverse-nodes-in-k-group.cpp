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
   
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
        {
            return NULL;
        }
        //reverse first k nodes
        int count = 0;
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *forward = NULL;
        ListNode *temp = head;
        
        // count remaining nodes
        int countNodes = 0;
        
         while(temp != NULL)
         {
            countNodes++;
            temp = temp->next;
        }
        
        if(countNodes >= k)
        {
            while(curr != NULL && count < k)
            {
                forward = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forward;
                count++;
            }
            //then do a recursion
            if(forward != NULL)
            {
                head->next = reverseKGroup(forward, k);
            }
        }
        else
        {
            return head;
        }
    
        //then return head of reverse list
        return prev;
    }
};