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
class comparator
{
    public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, comparator> minh;
        ListNode *head = new ListNode(0);   //a dummy node
        ListNode *temp = head;
        for(int i=0; i<n; i++)
        {
            if(lists[i] != NULL)
                minh.push(lists[i]);
        }
        while(!minh.empty())
        {
            ListNode *ele = minh.top();
            minh.pop();
            temp->next = ele;
            temp = temp->next;
            if(ele -> next != NULL)
                minh.push(ele->next);
        }
        return head->next;
    }
};