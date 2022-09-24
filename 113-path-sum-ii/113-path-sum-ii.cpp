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
    vector<int> fun(TreeNode* root,int target,vector<int> v2,vector<vector<int>>& v){
        
        if(root==NULL)
            return {};
        v2.push_back(root->val);
        if(root->val == target && root->left==NULL && root->right==NULL){
            return v2;
        }
        if(!(fun(root->left,target-root->val,v2,v).empty()))
            v.push_back(fun(root->left,target-root->val,v2,v));
        if(!(fun(root->right,target-root->val,v2,v).empty()))
            v.push_back(fun(root->right,target-root->val,v2,v));
         return {};
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> v;
        vector<int> v2;
        if(!fun(root,targetSum,v2,v).empty())
        v.push_back(fun(root,targetSum,v2,v));
        return v;
    }
};