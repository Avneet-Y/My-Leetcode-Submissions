//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
int find_position(int inorder[],int &ele, int start, int end)
    {
        for(int i=start; i<=end; i++)
        {
            if(inorder[i] == ele)
            return i;
        }
        return -1;
    }
    
    Node* build(int inorder[], int instart, int inend, int postorder[], int poststart, int postend)
    {
        if(instart > inend || poststart > postend)
        {
            return NULL;
        }
        Node *root = new Node(postorder[postend]);
        int inroot = find_position(inorder, root->data, instart, inend);
        
        int newleft = inroot - instart;
        root->left = build(inorder, instart, inroot-1, postorder, poststart, poststart+newleft-1);
        root->right = build(inorder, inroot+1, inend, postorder, poststart + newleft, postend - 1);
        return root;
        
    }
    
Node *buildTree(int inorder[], int postorder[], int n) {
    // Your code here
    Node* root = build(inorder, 0, n-1, postorder, 0, n-1);
        return root;
}
