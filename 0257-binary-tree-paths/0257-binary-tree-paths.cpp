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
    void solve(TreeNode* root, vector<string> &ans, string path)
    {
        if(root->right == NULL && root->left == NULL)
            ans.push_back(path);
        if(root->left != NULL)
        {
            solve(root->left, ans, path + "->" + to_string(root->left->val));
        }
        if(root->right != NULL)
        {
            solve(root->right, ans, path + "->" + to_string(root->right->val));
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root == NULL)
            return ans;
        solve(root, ans, to_string(root->val));
        return ans;
    }
};