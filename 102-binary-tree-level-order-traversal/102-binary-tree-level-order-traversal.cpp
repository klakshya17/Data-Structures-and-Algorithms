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
    void level_order(queue<TreeNode*> &q,vector<vector<int>> &v){
    if(q.empty())
            return;
    vector<int> temp;
    int s = q.size();
    for(int i=0;i<s;i++){
     if(q.front()->left!=NULL)
        q.push(q.front()->left);
     if(q.front()->right!=NULL)
        q.push(q.front()->right);
     temp.push_back(q.front()->val);
     q.pop();
    }
    v.push_back(temp);

    level_order(q,v);
    }
    
    
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        if(root!=NULL){
            q.push(root);
            level_order(q,v);
        }
        return v;
    }
};