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
    void inorder(TreeNode* root, vector<int> &invec)
    {
        if(root == NULL)
            return;
        inorder(root->left, invec);
        invec.push_back(root->val);
        inorder(root->right, invec);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> invec;
        inorder(root, invec);
        int i=0, j = invec.size()-1;
        while(i< j)
        {
            int sum = invec[i] + invec[j];
            if(sum == k)
                return true;
            else if(sum > k)
                j--;
            else
                i++;
        }
        return false;
        
        
    }
};