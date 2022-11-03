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

    int solve(TreeNode* root, int &ans)
    {
        if(root == nullptr)
            return 0;
        int lf = solve(root->left, ans);
        int rt = solve(root->right, ans);
        int height = 1 + max(lf, rt);
        ans = max(ans, 1 + lf + rt);
        return height;
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        int ans = INT_MIN;
        int x = solve(root, ans);
        return ans-1;
    }
};