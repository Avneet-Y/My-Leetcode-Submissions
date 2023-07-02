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
    void markparent(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &mpparent, int start, TreeNode* &startnode )
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if(curr->val == start)
                startnode = curr;
            if(curr->left != NULL){
                mpparent[curr->left] = curr; 
                q.push(curr->left);
            }
            if(curr->right != NULL){
                mpparent[curr->right] = curr; 
                q.push(curr->right);
            }
        }
    }
    
    
    
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> mpparent;
        TreeNode* startnode = NULL;
        unordered_map<TreeNode*, bool> visited;
        
        markparent(root, mpparent, start, startnode);
        
        visited[startnode] = true;
        queue<TreeNode*> q;
        q.push(startnode);
        int time = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            time++;
            for(int i=0; i<size; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left != NULL && visited[curr->left] != true)
                {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right != NULL && visited[curr->right] != true)
                {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if(mpparent[curr] != NULL && visited[mpparent[curr]] != true)
                {
                    q.push(mpparent[curr]);
                    visited[mpparent[curr]] = true; 
                }
            }
        }
        return time-1;
    }
};