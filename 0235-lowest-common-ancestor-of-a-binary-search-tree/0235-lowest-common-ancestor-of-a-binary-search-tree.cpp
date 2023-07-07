/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        int curr = root->val;
        if(curr < p->val && curr < q->val) //both val is more so on right
            return lowestCommonAncestor(root->right, p, q);
        
        if(curr > p->val && curr > q->val) //both val is less so on left
            return lowestCommonAncestor(root->left, p, q);
        
        return root; //dono hi ek side right nhi nhi hai naa hi left means ek left hai 
    }                   //ek right yhi apna ans hai
};