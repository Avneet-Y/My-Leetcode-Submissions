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
   
//     bool isValidBST(TreeNode* root) {
//     return isValidBST(root, NULL, NULL);
// }

// bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
//     if(root==NULL) 
//         return true;
//     if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
//         return false;
//     return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    
        vector<int> inord; // to store inorder order traversal
        void solve(TreeNode* root) 
        {
            if(root == NULL) 
                return; 
            solve(root->left);
            inord.push_back(root->val); 
            solve(root->right); 
        }
    
    bool isValidBST(TreeNode* root) {   
        solve(root);   //  in-order manner
        for(int i=1; i<inord.size(); i++) {
            if(inord[i] <= inord[i-1])   //  BST condition false
                return false; 
        }
        return true;    
    
    }
};