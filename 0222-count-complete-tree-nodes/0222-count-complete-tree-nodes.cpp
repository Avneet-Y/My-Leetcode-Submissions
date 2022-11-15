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
  int leftheight(TreeNode* root)
   {
       int h = 0;
       while(root)
       {
           h++;
           root = root->left;
       }
       return h;
   }
    int rightheight(TreeNode* root)
   {
       int h = 0;
       while(root)
       {
           h++;
           root = root->right;
       }
       return h;
   }
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        int lt = leftheight(root);
        int rt = rightheight(root);
        
        if(lt == rt)
            return pow(2, lt)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};