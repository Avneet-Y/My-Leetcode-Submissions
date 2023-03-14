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
    void solve(TreeNode* curr, int &total, int num)
    {
        if (curr == NULL) 
            return;
        
        num = (num * 10) + (curr -> val);
        if (curr->left == NULL && curr->right == NULL)  
        {
            total += num;
            return; 
        }
        solve(curr->left, total, num);
        solve(curr->right, total, num);
    }
    int sumNumbers(TreeNode* root) 
    {
        int total = 0;
        solve(root, total, 0);
        return (total); 
        
    }
};