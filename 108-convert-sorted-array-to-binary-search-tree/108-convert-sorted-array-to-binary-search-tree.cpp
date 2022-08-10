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
    void fun(int left,int right, TreeNode* root,vector<int> & nums){
        int index=0;
        if(left>right)
            return;
        else if(left==right)
            index=left;
        else 
            index = left+(right-left)/2;
        
        root->val = nums[index];
        cout<<index;
        
        if(left<index){
            TreeNode* leftNode = new TreeNode;
            root->left = leftNode;
            fun(left,index-1,leftNode,nums);
        }
        if(right>index){
            TreeNode* rightNode = new TreeNode;
            root->right=rightNode;
            fun(index+1,right,rightNode,nums);
        }
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = new TreeNode;
        fun(0,nums.size()-1,root,nums);
        return root;
    }
};