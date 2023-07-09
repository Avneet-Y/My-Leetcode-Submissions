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
class NodeVal{
    public:
    bool isbst;
    int minNode, maxNode, maxSum;
    NodeVal()
    {
        isbst = true;
        minNode = INT_MAX;
        maxNode = INT_MIN;
        maxSum= 0;
    }
};
int ans;
    
class Solution {
public:
    NodeVal FindSum(TreeNode* root)
    {
    if(root == NULL) 
        return NodeVal();
    NodeVal curr;
    // Postorder trav used
    NodeVal left = FindSum(root->left);
    NodeVal right = FindSum(root->right);

    if((left.isbst == true && right.isbst == true) && (left.maxNode<root->val && root->val<right.minNode)){
        
        curr.isbst = true;
        curr.maxSum = left.maxSum + right.maxSum+root->val;
        curr.minNode= min(left.minNode,root->val);
        curr.maxNode = max(right.maxNode,root->val);
    }
    else
    {
        curr.isbst = false; 
        curr.maxSum = max(left.maxSum,right.maxSum);
    }
    ans = max(ans,curr.maxSum);
    return curr;
}
    int maxSumBST(TreeNode* root) {
        ans = 0;
        NodeVal obj = FindSum(root);
        return ans;
        
    }
};