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
//     int diameterOfBinaryTree(TreeNode* root) {
//         int diameter = 0;
//         height(root, diameter);
//         return diameter;
//     }
//     // private:
//     int height(TreeNode* node, int& diameter)
//     {
//         if(node == NULL)
//             return 0;
//         int left_ht = height(node->left, diameter);
//         int right_ht = height(node->right, diameter);
//         diameter = max(diameter, left_ht + right_ht);
//         return 1 + max(left_ht, right_ht);
//     }
// };



class Solution {
public:

    int solve(TreeNode* root, int &res)
    {
        if(root == nullptr)
            return 0;
        int lf = solve(root->left, res);
        int rt = solve(root->right, res);
        int temp = 1 + max(lf, rt);
        res = max(1 + lf + rt, res);
        return temp;
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        int res = INT_MIN;
        int x = solve(root, res);
        return res-1;           //as we are not including the starting node
    }
};