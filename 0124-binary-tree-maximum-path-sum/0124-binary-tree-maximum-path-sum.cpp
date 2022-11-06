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
    int solve(TreeNode* root, int &res){
        if(root == NULL)
        {
            return 0;
        }
        int lt = solve(root->left, res);
        int rt = solve(root->right, res);
        
        int temp = max(max(lt, rt) + root->val, root->val);
        int ans = max(root->val + lt + rt, temp);
        res = max(res, ans);
        return temp;
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        int bt = solve(root, res);
        return res;
    }
};

