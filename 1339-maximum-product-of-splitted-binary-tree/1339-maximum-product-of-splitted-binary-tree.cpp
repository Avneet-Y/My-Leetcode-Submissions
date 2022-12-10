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
     
    long totalSum = 0, maxPro = 0;
   
    void tsum(TreeNode* root) {
        if(root == NULL) 
            return;
        tsum(root -> left);
        tsum(root -> right);
        totalSum += root -> val;
    }
    long maxproduct(TreeNode* root)
    {
        if(root == NULL) 
            return 0;
        long lt = maxproduct(root->left);
        long rt = maxproduct(root->right);
        long subsum = lt + rt + root->val;
        maxPro = max(maxPro, (totalSum - subsum) * subsum);
        return subsum;
    }
    int maxProduct(TreeNode* root) {
        tsum(root);
        maxproduct(root);
        return (int)(maxPro%1000000007);
    }
};