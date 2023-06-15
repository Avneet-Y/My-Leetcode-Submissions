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
    void insertattail(Node* &head, Node* &tail, int val)
    {
        Node* temp = new Node(val);
        if(head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }   
    }
    
    Node* copyRandomList(Node* head) {
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        
        Node* temp = head;
        while(temp != NULL)
        {
            insertattail(clonehead, clonetail, temp->val);
            temp = temp->next;
        }
        
        Node* originalnode = head;
        Node* clonenode = clonehead;
        
        
        while(originalnode != NULL && clonenode != NULL)
        {
            Node* nextnode = originalnode->next;
            originalnode->next = clonenode;
            originalnode = nextnode;
            
            nextnode = clonenode->next;
            clonenode->next= originalnode;
            clonenode = nextnode;
        }
        
        temp = head;
        
        while(temp != NULL)
        {
            if(temp->next != NULL)
            {
                if(temp->random != NULL)
                {
                    temp->next->random = temp->random->next;
                }
                else
                {
                    temp->next->random = temp->random;  //temp->next = NULL;
                }
            }
            temp = temp->next->next;
        }
        
        clonenode = clonehead;
        originalnode = head;
        
        while(originalnode != NULL && clonenode != NULL)
        {
            originalnode->next = clonenode->next;
            originalnode = originalnode->next;
            if(originalnode != NULL)
            {
                clonenode->next = originalnode->next;
            }
            clonenode = clonenode->next;
        }
        return clonehead;
    }
};