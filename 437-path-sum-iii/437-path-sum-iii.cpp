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
    int ans =0;
    int fun(TreeNode* root, long long int target){
    if(root==NULL)
        return 0;
    int sum = fun(root->left,target-root->val)+fun(root->right,target-root->val);
        if(root->val == target)
            sum++;
        return sum;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return 0;
        return fun(root,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum); 
    }
};