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
    int ans=0;
    void fun(TreeNode* root, int num){
        num+=root->val;
        if(!(root->left || root->right)){
            ans+=num;
            return;
        }
        if(root->left){
            fun(root->left,num*10);
        }
        if(root->right){
            fun(root->right,num*10);
        }
    }
    int sumNumbers(TreeNode* root) {
        fun(root,0);
        return ans;
    }
};