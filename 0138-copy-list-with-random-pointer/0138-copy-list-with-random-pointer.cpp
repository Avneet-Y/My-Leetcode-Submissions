/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertattail(Node* &head1, Node* &tail, int val)
    {
        Node* newnode = new Node(val);
        if(head1 == NULL)
        {
            head1 = newnode;
            tail = newnode;
            return;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
    
    Node* copyRandomList(Node* head) {
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        Node* temp = head;
        
        unordered_map<Node*, Node*> mp;  //map of original to clone ll
        
        while(temp != NULL)
        {
            insertattail(clonehead, clonetail, temp->val);
            temp = temp->next;
        }
        Node* originalnode = head;
        Node* clonenode = clonehead;
        
        while(originalnode != NULL)  //normally mapped
        {
            mp[originalnode] = clonenode;
            originalnode = originalnode->next;
            clonenode = clonenode->next;   
        }
        
        originalnode = head;
        clonenode = clonehead;
        
        while(originalnode != NULL)  //for mapping random ptrs
        {
            clonenode->random = mp[originalnode->random];
            originalnode = originalnode->next;
            clonenode = clonenode->next;
        }
        return clonehead;
    }
};