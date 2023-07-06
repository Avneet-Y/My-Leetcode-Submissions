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
    TreeNode *findlastright(TreeNode * root)
    {
        if(root->right == NULL)
            return root;
        return findlastright(root->right);
    }
    
    TreeNode *solve(TreeNode* root)
    {
        if(root->left == NULL)
            return root->right;
        
        else if(root->right == NULL)
            return root->left;
        
        TreeNode *rightchild = root->right;
        TreeNode *lastright = findlastright(root->left);
        lastright->right = rightchild;
        return root->left;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return NULL;
        if(root->val == key)
            return solve(root);
        
        TreeNode *curr = root;
        while(curr != NULL)
        {
            if(curr -> val >= key)
            {
                if(curr->left != NULL && curr->left->val == key)
                {
                    curr->left = solve(curr->left);
                    break;
                }
                else
                {
                    curr = curr->left;
                }
            }
            else if(curr->val <= key)
            {
                if(curr->right != NULL && curr->right->val == key)
                {
                    curr->right = solve(curr->right);
                    break;
                }
                else
                {
                    curr = curr->right;
                }
            }
        }
        return root;
    }
};