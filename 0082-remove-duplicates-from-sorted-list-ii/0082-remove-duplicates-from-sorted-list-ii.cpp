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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) 
            return NULL;
        if(head->next == NULL) 
            return head;
        
        ListNode* temp = head;
        ListNode* newnode = new ListNode(0);
        map<int, int> mp;
        
        while(temp != NULL)
        {
            mp[temp->val]++;
            temp = temp->next;
        }
        temp = newnode;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            if(it->second == 1)
            {
                temp->next = new ListNode(it->first);
                temp = temp->next;
            }
        }
        return newnode->next;
    }
};