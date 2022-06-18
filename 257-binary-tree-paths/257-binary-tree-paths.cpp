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
    vector<string> v;
    void fun(TreeNode* root,string s){
        if(root==NULL)
            return ;
        if(!s.size())
            s += to_string(root->val);    
        else
            s = s + "->" + to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            v.push_back(s);
        }
        fun(root->left,s);
        fun(root->right,s); 
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        fun(root,"");
        return v;
    }
};