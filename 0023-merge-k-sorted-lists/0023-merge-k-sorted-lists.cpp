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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<int> ans;
        int n = lists.size();
        for(int i=0; i<n; i++)
        {
            ListNode *head = lists[i];
            while(head != NULL)
            {
                ans.push_back(head->val);
                head = head->next;
            }
        }
        sort(ans.begin(), ans.end());
        ListNode * temp = new ListNode(0);
        ListNode* ptr = temp;
        for(int i=0; i < ans.size(); i++)
        {
            temp->next = new ListNode(ans[i]);
            temp = temp->next;
        }
        return ptr->next;
    }
};