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
    void reverse(ListNode* &head, ListNode* &curr, ListNode* &prev)
    {
        if(curr == NULL)
        {
            head = prev;
            return;
        }
        ListNode* forward = curr->next;
        reverse(head, forward, curr);
        curr->next = prev;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        reverse(head, curr, prev);
        return head;
    }
};