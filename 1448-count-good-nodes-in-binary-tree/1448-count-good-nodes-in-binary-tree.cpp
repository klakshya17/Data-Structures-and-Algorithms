class Solution {
public:
    int count = 0;
    
    void inorder(TreeNode* root, int m = -100000)
    {
        if (root==NULL) {return;}
        if (root->val>=m) {count++;}
        inorder(root->left, max(root->val, m));
        inorder(root->right, max(root->val, m));
        return;
    }
        
    int goodNodes(TreeNode* root) {
        inorder(root);
        return count;
    }
};