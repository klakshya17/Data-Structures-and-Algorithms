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
    TreeNode* lca(TreeNode* root,TreeNode* a, TreeNode* b){
      if(root==NULL)
          return NULL;
      
      // if(root->left == a || root->left == b)
      //     return root->left;
      // if(root->right == a || root->right == b)
      //     return root->right;
        
        if(root==a || root==b)
            return root;
     
      TreeNode * p = lca(root->left,a,b);
      TreeNode * q = lca(root->right,a,b);
      
        
        if(p==NULL && q==NULL)
            return NULL;
        else if(p && q)
            return root;
        else if(p)
            return p;
        else return q;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p,q);
    }
};