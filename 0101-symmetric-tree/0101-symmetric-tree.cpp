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
    bool symmetricsolve(TreeNode* leftn, TreeNode* rightn)
    {
        if(leftn == NULL || rightn == NULL)
            return leftn == rightn;
        if(leftn->val != rightn->val)
            return false;
        return symmetricsolve(leftn->left, rightn->right) && symmetricsolve(leftn->right, rightn->left);
            
    }
        
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return symmetricsolve(root->left, root->right);
    }
};