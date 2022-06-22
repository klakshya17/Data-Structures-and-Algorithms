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
    int ans=INT_MIN;
    int fun(TreeNode* root){
        if(root==nullptr)
            return 0;
        int left = max(0,fun(root->left));
        int right = max(0,fun(root->right));
        
        int sum = max(root->val,max(right,left)+root->val);
        // ans = max(ans,sum);
        
        ans= max((left+right+root->val),ans);
        
        return sum;
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
            return INT_MIN;
        int a = fun(root);
        ans = max(ans,a);
        return ans;
        // return max(ans,max(maxPathSum(root->right),maxPathSum(root->left)));
    }
};