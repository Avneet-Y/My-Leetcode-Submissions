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
        unordered_set<ListNode*> set;
        ListNode *curr = head;
        while(curr != NULL)
        {
            if(set.find(curr) != set.end())
            {
                return curr;
            }
            else 
            {
                set.insert(curr);
                curr = curr->next;   
            }
        }
        return NULL;
        
    }
};



