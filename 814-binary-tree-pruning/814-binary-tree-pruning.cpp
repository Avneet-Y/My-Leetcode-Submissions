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
// class Solution {
// public:
//     int helper(TreeNode* root)
//     {
//         if(root==NULL)
//             return 0;
        
//         if(root->left == NULL && root->right == NULL)
//         {
//             if(root->val == 0)
//                 return 0;
//             else
//                  return 1;
//         }
        
//         int leftsubt = helper(root->left);
//         int rightsubt = helper(root->right);
        
//         if(leftsubt == 0)
//             root->left = NULL;
        
//         if(rightsubt == 0)
//             root->right = NULL;
        
//         return leftsubt + rightsubt + (root->val == 1 ? 1 : 0);
            
//     }
    
//     TreeNode* pruneTree(TreeNode* root) {
//         //subtree me se 1 vali nodes remove krni hai
        
//         if(helper(root) == 0)
//             return NULL;
        
//         return root;
    
    
    
    
//     }
// };


class Solution {
public:
         
    TreeNode* pruneTree(TreeNode* root) {
        
        if (root == NULL) 
            return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->val == 1 || root->left != NULL || root->right != NULL) 
            return root; //current subtree contain 1 or not?
        return NULL;     
    }
};
