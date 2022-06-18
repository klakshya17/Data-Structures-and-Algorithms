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
    unordered_map<TreeNode*,TreeNode*> um;
    vector<int> v;
    void findParents(TreeNode* root,TreeNode* parent,TreeNode* target){
        if(parent==target || root==NULL)
            return;
        else um[root] = parent;
        findParents(root->left,root,target);
        findParents(root->right,root,target);
    }
    void top(TreeNode* root, int d,TreeNode* child){
        if(root==NULL)
            return;
         if(d==0)
            v.push_back(root->val);
        else {
            if(child==root->left)
                fun(root->right,d-1);
            else
                fun(root->left,d-1);
            top(um[root],d-1,root);
        }
            
    }
    void fun(TreeNode* root, int d){
        if(root==NULL)
            return;
        if(d==0)
            v.push_back(root->val);
        else {
            fun(root->right,d-1);
            fun(root->left,d-1);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findParents( root,NULL,target);
        // cout<<um[target]->val;
        top(um[target],k-1,target);
        fun(target,k);
        return v;
    }
};