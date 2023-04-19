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
    int finalans = 0;
    void solve(TreeNode* root, int way, int ans)
    {
        if(!root)
        {
            return;
        }

        finalans = max(finalans, ans);

        if(way == 0)
        {
            solve(root->left, 1, ans+1);
            solve(root->right, 0, 1);
        }
        else
        {
            solve(root->right, 0, ans+1);
            solve(root->left, 1, 1);
        }
    }
    int longestZigZag(TreeNode* root) {
        solve(root, 0, 0);
        solve(root, 1, 0);
        return finalans;
        
    }
};