/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* fun(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL)
            return NULL;
        
        if(root==p || root==q)
            return root;
        
        TreeNode* a = fun(root->left,p,q);
        TreeNode* b = fun(root->right,p,q);
        
        if(!(a || b)) //both are NULL return NULL
            return NULL;
        
        if(a && b) //both are not NULL, return this node as the answer
            return root;
        
        //one is NULL return the other 
        if(a) return a;
        else return b;
     }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return fun(root,p,q);
    }
};