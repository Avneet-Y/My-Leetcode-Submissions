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
     void solve(TreeNode* root, int target, int curr_Sum, vector<int> temp, vector<vector<int>> &ans){
		
        temp.push_back(root -> val);
        curr_Sum += root -> val;
        if(curr_Sum == target && (root->left == NULL && root->right == NULL))
        {
            ans.push_back(temp);
            return;
        }
        if(root->left == NULL && root->right == NULL)
        {
            return;
        }
		
        if(root -> left != NULL)
            solve(root->left, target, curr_Sum, temp, ans);
        
         if(root -> right != NULL) 
            solve(root->right, target, curr_Sum, temp, ans);
        
         return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        if(root == NULL) 
            return ans;
        
        solve(root, targetSum, 0, temp, ans);
        return ans;
    }
};