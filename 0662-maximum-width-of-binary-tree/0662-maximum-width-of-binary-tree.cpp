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
   int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int ans = INT_MIN;
        while(!q.empty())
        {
            int size = q.size();
            int min = q.front().second;
            int first, last;
            
            for(int i = 0; i < size; i++)
            {
                TreeNode* curr = q.front().first;
                int curr_idx = q.front().second;
                curr_idx -= min;
                q.pop();
                if(i == 0)
                {
                    first = curr_idx;
                }
                if(i == size-1)
                {
                    last = curr_idx;
                }
                if(curr->left)
                {
                    q.push({curr->left, (long long)2*curr_idx + 1});
                }
                if(curr->right)
                {
                    q.push({curr->right, (long long)2*curr_idx + 2});
                }
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};