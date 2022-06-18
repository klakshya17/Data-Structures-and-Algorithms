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
    int fun(TreeNode* node, int low, int high){
        if(node==NULL)
            return 0;
        if(node->val <= high && node->val >= low)
            return fun(node->left,low,high) + fun(node->right,low,high) + node->val;
        else if(node->val < low )
            return fun(node->right,low,high);
        else 
            return fun(node->left,low,high);   
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return fun(root,low,high);
    }
};