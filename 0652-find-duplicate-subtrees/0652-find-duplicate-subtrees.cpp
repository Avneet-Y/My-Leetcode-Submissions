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
    unordered_map<string, int> mp;
    vector<TreeNode*> res;
    string dfs(TreeNode* root)
    {
        if(root == NULL)
        {
            return "";
        }
        string str = "";
        str += to_string(root -> val);
        str += "#";
        string left = dfs(root -> left);
        str += left;
        str += "#";
        string right = dfs(root -> right);
        str += right;
        mp[str]++;
        if(mp[str] == 2)
        {
            res.push_back(root);
        }
        return str;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return res;  
    }
};