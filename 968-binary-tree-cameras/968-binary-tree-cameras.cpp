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
    int cam = 0;
    int fun(TreeNode* root){
        if(root==NULL)
            return 1;
        
        int left = fun(root->left);
        int right = fun(root->right);
        
        if(left==-1 || right==-1){
            cam+=1;
            return 0;
        }
        else if(left==1 && right ==1){
            return -1;
        }
        else{
            return 1;
        }
    }
    int minCameraCover(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 1;
        int a = fun(root);
        if(a==-1)
            cam+=1;
        return cam;
    }
};