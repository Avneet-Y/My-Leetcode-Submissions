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


// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         int depth = 0;
        
//         if (root == NULL) return depth;
        
//         queue<TreeNode*> q;
//         q.push(root);
        
//         while (!q.empty()) {
//             int size = q.size();
//             depth++;
//             for (int i = 0; i < size; i++) {
//                 TreeNode* temp = q.front();
//                 q.pop();
//                 if (temp -> left != NULL) q.push(temp -> left);
//                 if (temp -> right != NULL) q.push(temp -> right);
//             }
//         }
//         return depth;
//     }
// };



class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int left_ht = maxDepth(root->left);
        int right_ht = maxDepth(root->right);
        
        return 1 + max(left_ht, right_ht);
        
        
    }
};