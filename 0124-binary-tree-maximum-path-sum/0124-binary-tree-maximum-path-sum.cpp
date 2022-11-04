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
    int dp(TreeNode* root, int &res){
        if(root == NULL)
        {
            return 0;
        }
        int leftSum = dp(root->left, res);
        int rightSum = dp(root->right, res);
        
        int pathSum = max(root->val + max(leftSum, rightSum), root->val);
        int totalSum = max(pathSum, root->val + leftSum + rightSum);
        res = max(res, totalSum);
        return pathSum;
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dp(root, res);
        return res;
    }
};

