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
    bool isCompleteTree(TreeNode* root) {
        vector<TreeNode*> ans;
        ans.push_back(root);
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL)
                continue;
            q.push(temp -> left);
            ans.push_back(temp -> left);
            q.push(temp -> right);
            ans.push_back(temp -> right);
        }
        int i = 0;
        int flag = 0;
        while(i < ans.size())
        {
            if(ans[i] == NULL)
                flag = 1;
            else if(flag == 1)
                return false;
            i++;
        }
        return true;
        
    }
};