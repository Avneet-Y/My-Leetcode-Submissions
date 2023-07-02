/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parentmp)
    {               //marking all child node's parents as node, parent 
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left != NULL)
            {
                parentmp[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right != NULL)
            {
                parentmp[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*, TreeNode*> parentmp;
        markparent(root, parentmp);
        
        unordered_map<TreeNode*, bool> visited;  //visited map so parent na include kre 
                                                    //vapas and mark visited
        queue<TreeNode*> q;
        visited[target] = true; //start with the target and push in q
        q.push(target);
        int currlvl = 0;   //node se agli node ke distance
        
        while(!q.empty())
        {
            int size = q.size();
            if(currlvl == k)
                break;
            currlvl++;
            for(int i=0; i<size; i++)
            {
                TreeNode* currnode = q.front();
                q.pop();
                if(currnode->left != NULL && visited[currnode->left] != true)
                {
                    q.push(currnode->left);
                    visited[currnode->left] = true;
                }
                if(currnode->right != NULL && visited[currnode->right] != true)
                {
                    q.push(currnode->right);
                    visited[currnode->right] = true;
                }
                if(parentmp[currnode] != NULL && visited[parentmp[currnode]] != true)
                {
                    q.push(parentmp[currnode]);
                    visited[parentmp[currnode]] = true;            
                }
            }
        }
        while(!q.empty())   //q me targetnode se jaane vale dis ke nodes gye hai
        {
            TreeNode *node = q.front();
            q.pop();                
            ans.push_back(node->val);
        }
        return ans; 
    }
};