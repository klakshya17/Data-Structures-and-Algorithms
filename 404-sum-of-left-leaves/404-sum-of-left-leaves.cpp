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
    int count = 0;
    void func(TreeNode* root, bool isleft){
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
            if(isleft){
                count+= root->val;
            }
            return;
        }
        
        if(root->left)  func(root->left, 1);
        if(root->right) func(root->right, 0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        func(root, 0);
        return count;
    }
};