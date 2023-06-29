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
    int pathsum(TreeNode* root, int &maxsum)
    {
        if(root == NULL)
            return 0;
        int leftsum = max(0, pathsum(root->left, maxsum));
        int rightsum = max(0, pathsum(root->right, maxsum)); //if i get -ve no from them i will return 0
        maxsum = max(maxsum, root->val + leftsum + rightsum);
        return (root->val) + max(leftsum, rightsum);
    }
    
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        pathsum(root, sum);
        return sum;
    }
};