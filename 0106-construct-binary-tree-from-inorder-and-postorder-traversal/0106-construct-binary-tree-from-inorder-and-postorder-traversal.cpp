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
    int i;
    int search(vector<int>& in, int start, int end, int val)
    {
        for(int i = start; i <= end; i++)
        {
            if(in[i] == val)
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode* construct(vector<int>& post, int start, int end, vector<int>& in)
    {
        if(start > end)
        {
            return NULL;
        }
        int val = post[i];
        i--;
        int idx = search(in, start, end, val);
        TreeNode* root = new TreeNode(val);
        root -> right = construct(post, idx + 1, end, in);
        root -> left = construct(post, start, idx - 1, in);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        
        int n = in.size();
        i = n-1;
        return construct(post, 0, n - 1, in);
    }
};