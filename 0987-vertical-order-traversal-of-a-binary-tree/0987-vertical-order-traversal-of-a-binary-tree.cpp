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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int , int>>> que;//node, pair me level|, vertical-store
        map<int, map<int, multiset<int>>> mp;
        
        que.push({root, {0, 0}});
        
        while(!que.empty())
        {
            auto p = que.front();
            que.pop();
            TreeNode *node = p.first;
            
            int vert = p.second.first;
            int level = p.second.second;
            
            mp[vert][level].insert(node->val);
            if(node->left != NULL)
            {
                que.push({node->left, {vert-1, level+1}});
            }
            if(node->right != NULL)
            {
                que.push({node->right, {vert+1, level+1}});
            }
        }
        
        for(auto p : mp)
        {
            vector<int> temp;
            for(auto q : p.second)
            {
                temp.insert(temp.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};