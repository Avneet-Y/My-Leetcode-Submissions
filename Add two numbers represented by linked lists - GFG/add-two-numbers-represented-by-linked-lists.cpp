//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    //Function to add two numbers represented by linked list.
    Node* reverse(Node* head)
    {
        Node* temp = head;
        Node* forward = NULL;
        Node* prev = NULL;
        
        while(temp != NULL)
        {
            forward = temp->next;
            temp->next = prev;
            prev = temp;
            temp = forward;
        }
        return prev;
    }
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
             tail->next  = temp;
             tail = temp;
         }
     }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
         int carry = 0;
         first = reverse(first);
         second = reverse(second);
        Node* anshead = NULL;
        Node* anstail = NULL;
        
        while(first != NULL || second != NULL || carry != 0)
        {
            int val1 = 0, val2 = 0;
            if(first != NULL)
            {
                val1 = first->data;
            }
            
            if(second != NULL)
            {
                val2 = second->data;
            }
            
            int sum = carry + val1 + val2;
            int digit = sum%10;
            insertattail(anshead, anstail, digit);
            carry = sum/10;
            if(first != NULL)
            {
                first = first->next;
            }
            if(second != NULL)
            {
                second = second->next;
            }
        }
        anshead = reverse(anshead);
        return anshead;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends