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
    string tree2str(TreeNode* root) {
        
        string ans;
        
        auto infunction = [&ans](TreeNode* root,auto &&self)->void
        {
        
            if(root == NULL)
                return;
        
            ans += to_string(root->val);
        
            if(root->right == NULL && root->left == NULL)
            {
                return;
            }
            
            ans.push_back( '(' );
            self(root->left, self);
            ans.push_back( ')' );
            
            if(root->right != NULL)
            {
                ans.push_back( '(' );
                self(root->right, self);
                ans.push_back( ')' );
            }
        };
        
        infunction(root, infunction);
        return ans;
        
    }
};