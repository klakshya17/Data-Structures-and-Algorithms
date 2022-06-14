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
    void levelOrder(TreeNode* root,vector<vector<int>> &v){
        // queue<TreeNode*> q;
        stack<TreeNode*> s,r;
        r.push(root);
        
        bool k=true;
        
        while(!r.empty() || !s.empty()){
            vector<int> v2;
            
            if(k)
            while(!r.empty()){
                if(r.top()->left)
                    s.push(r.top()->left);
                if(r.top()->right)
                    s.push(r.top()->right);
                v2.push_back(r.top()->val);
                r.pop();
            }
            
            else
            while(!s.empty()){
                if(s.top()->right)
                    r.push(s.top()->right);
                if(s.top()->left)
                    r.push(s.top()->left);
                v2.push_back(s.top()->val);
                s.pop();
            }
            
            v.push_back(v2);
            k=!k;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        deque<TreeNode*> q;
        q.push_back(root);
        vector<vector<int>>v;
        levelOrder(root,v);
        return v;
    }
};