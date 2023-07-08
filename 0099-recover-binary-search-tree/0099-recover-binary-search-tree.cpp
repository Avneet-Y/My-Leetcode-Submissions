/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *first, *prev, *middle, * last;
    void inorder(TreeNode* root)
    {
        if(root == NULL)
            return;
        inorder(root->left);
        if(prev != NULL && root->val < prev->val)  //1st violation
        {
            if(first == NULL)  //if its 1st violate, mark it as first mid
            {
                first = prev;
                middle = root;
            }
            else   //second violate first last
                last = root;
        }
        prev = root;
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        first, middle, last, prev = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last)
            swap(first->val, last->val);   //2nd violate
        else if(first && middle)
            swap(first->val, middle->val); //1 violate
    }
};