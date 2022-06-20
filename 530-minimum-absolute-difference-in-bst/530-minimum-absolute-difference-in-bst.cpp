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
    vector<int> v;
    void fun(TreeNode* root){
        if(root==NULL)
            return;
        fun(root->left);
        v.push_back(root->val);
        fun(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
           fun(root);
        int ans = INT_MAX;
        for(int i=1;i<v.size();i++)
            ans= min(v[i]-v[i-1],ans);
        return ans;
    }
};