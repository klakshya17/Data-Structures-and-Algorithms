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
    bool fun(TreeNode* a,TreeNode* b){
        if(a==NULL && b==NULL) //both are NULL
            return true;
        if(a==NULL || b==NULL) //only one is NULL
            return false;
        
        if(a->val != b->val)
            return false;
        
        return (fun(a->left,b->right) && fun(a->right,b->left));
        
    }
    bool isSymmetric(TreeNode* root) {

        return fun(root->left,root->right);
    }
};