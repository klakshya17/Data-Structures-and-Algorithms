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
    vector<TreeNode*> fun(int start,int end){
        vector<TreeNode*> v;
        if(start>end){
            v.push_back(NULL);
            return v;
        }
        else if(start==end){
            v.push_back(new TreeNode(start));
            return v;
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode*> left = fun(start,i-1);
            vector<TreeNode*> right = fun(i+1,end);
            
            for(auto l:left)
                for(auto r:right){
                    TreeNode* node = new TreeNode(i);
                    node->left = l;
                    node -> right = r;
                    v.push_back(node);
                }
        }
        return v;
    }
    vector<TreeNode*> generateTrees(int n) {
     return fun(1,n);   
    }
};