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
    unordered_map<int,int> um;
    int fun(TreeNode* root){
        if(root == NULL)
            return 0;
        int sum = fun(root->left)+fun(root->right)+root->val;
        // cout<<sum;
        um[sum]+=1;
        return sum;
    }    
    vector<int> findFrequentTreeSum(TreeNode* root) {
     if(root==NULL)
         return {};
       int a = fun(root);
    int large = INT_MIN;
     vector<int> v;   
     for(auto i:um)
         if(i.second>large)
             large = i.second;
    cout<<large;
    for(auto i:um)
         if(i.second==large)
             v.push_back(i.first);
    return v;
    }
};