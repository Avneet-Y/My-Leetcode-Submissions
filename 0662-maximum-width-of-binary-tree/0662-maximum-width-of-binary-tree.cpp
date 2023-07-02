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
        if(root == NULL)
            return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});  //doing a 0 based indexing
        
        while(!q.empty()){
            int size = q.size();
            int minind_on_lvl = q.front().second; //i take min ind on that level
            int first , last;
            for(int i=0; i<size; i++)
            {
                int curr_ind = q.front().second - minind_on_lvl; //modify acc to min
                TreeNode *node = q.front().first;
                q.pop();
                if(i == 0)
                    first = curr_ind;   //store first ind
                if(i == size - 1)
                    last = curr_ind; //store last one in that level
                if(node->left != NULL)
                    q.push({node->left, (long long)2*curr_ind + 1});
                
                if(node->right != NULL)
                    q.push({node->right, (long long)2*curr_ind + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};