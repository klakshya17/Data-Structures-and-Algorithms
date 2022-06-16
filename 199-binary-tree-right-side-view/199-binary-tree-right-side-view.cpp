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
    void fun(queue<TreeNode*> q){
        while(!q.empty()){
            // cout<<q.front()->val<<" ";
            v.push_back(q.front()->val);
            int s = q.size();
            while(s--){
                if(q.front()->right)
                    q.push(q.front()->right);
                if(q.front()->left)
                    q.push(q.front()->left);
                q.pop();
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root!=NULL){
            queue<TreeNode*> q;
            q.push(root);
            fun(q);
        }
        return v;   
    }
};