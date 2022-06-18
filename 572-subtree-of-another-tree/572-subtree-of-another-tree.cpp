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
    bool fun(TreeNode* root, TreeNode* subRoot){
        if(subRoot==NULL && root==NULL )
            return true;
        if(subRoot == NULL ||  root==NULL)
            return false;
        if(root->val != subRoot->val)
            return false;
        return  fun(root->left,subRoot->left) && fun(root->right,subRoot->right);
 
        // return (fun(root->left,subRoot->left)  && fun(root->right,subRoot->right) || fun(root->left,subRoot) || fun(root->right,subRoot) );
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL && root==NULL )
            return true;
        if(subRoot == NULL ||  root==NULL)
            return false;
        return fun( root, subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right, subRoot);
    }
};