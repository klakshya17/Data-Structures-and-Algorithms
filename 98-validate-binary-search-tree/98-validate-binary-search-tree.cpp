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
    void inorder(TreeNode* root, long int &curr,long int &a){
        if(root==NULL)
            return;
        inorder(root->left,curr,a);
        if(curr>=root->val)
        {
            a=1;
            return;
        }
        else curr=root->val;
        inorder(root->right,curr,a);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        long int curr=LONG_MIN,a=0;
        inorder(root,curr,a);
        // for(int i=1;i<v.size();i++){
        //     if(v[i]<=v[i-1])
        //         return false;
        // }
        if(a==0)
        return true;
        else return false;
    }
};