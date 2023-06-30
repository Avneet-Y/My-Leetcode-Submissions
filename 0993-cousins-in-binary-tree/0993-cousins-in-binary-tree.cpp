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
    int heightx = 0;
    int heighty = 0;
    int parentx = -1;
    int parenty = -1;
    
    void dfs(TreeNode* root, int x, int y, int height, int parent)
    {
        if(root == NULL)
            return;
        if(root -> val == x)
        {
            heightx = height;
            parentx = parent;
        }
        if(root -> val == y)
        {
            heighty = height;
            parenty = parent;
        }
        dfs(root -> left, x, y, height + 1, root -> val);
        dfs(root -> right, x, y, height + 1, root -> val);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, x, y, 0, -1);
        if(heightx != heighty)
            return false;
        if(heightx == heighty)
            return parentx != parenty;
        
        return false;
        
    }
};