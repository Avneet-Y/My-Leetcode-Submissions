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
   int ans=0;
    void help(TreeNode* root,int maxi){
        if(root==NULL)
            return;
        if(root->val >= maxi)
        { 
            ans++; 
            maxi = root->val; 
        }
        help(root->left, maxi);
        help(root->right, maxi);
    }
public:
    int goodNodes(TreeNode* root) {
        help(root, INT_MIN);
        return ans;  
    }
};