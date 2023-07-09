/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return NULL;
        if(root -> left != NULL)   
        {
            root->left->next = root->right;  //2 ka next connected to 3 , root(1)
        }
        if(root->right != NULL && root->next != NULL)  
        {
            root->right->next = root->next->left;  //root(2) 5 ka next connect to 2 ke 
        }                                          //next i.e 3 ka left
        connect(root->left);
        connect(root->right);
        return root;
    }
};