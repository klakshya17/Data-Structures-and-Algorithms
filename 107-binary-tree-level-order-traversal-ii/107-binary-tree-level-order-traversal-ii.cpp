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
    // int dfs(TreeNode* root){
    //     if(root==nullptr)
    //         return 0;
    //     return max(dfs(root->left),dfs(root->right))+1;
    // }
    
    vector<int> levelOrder(vector<vector<int>>& v,queue<TreeNode*>&q){
        if(q.empty())
        return {};
            
        vector<int> v2;
        int s = q.size();
        for(int i=0;i<s;i++){
            v2.push_back(q.front()->val);
            if(q.front()->left)
            q.push(q.front()->left);
            if(q.front()->right)
            q.push(q.front()->right);
            q.pop();
        }
        vector<int> v3 = levelOrder(v,q);;
        if(!v3.empty())
            v.push_back(v3);
        return v2;
    }
        
//     void levelOrder(TreeNode* root, vector<vector<int>>& v,queue<TreeNode*>&q){
//         while(!q.empty()){    
//         vector<int> v2;
//         int s = q.size();
//         for(int i=0;i<s;i++){
//             v2.push_back(q.front()->val);
//             if(q.front()->left)
//             q.push(q.front()->left);
//             if(q.front()->right)
//             q.push(q.front()->right);
//             q.pop();
//         }
//         v.push_back(v2);
//         }
        
//     }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==nullptr)
            return {};
        vector<vector<int>> v;
        queue<TreeNode*> q;
        q.push(root);
        v.push_back(levelOrder(v,q));
        // reverse(v.begin(),v.end());
        return v;
    }
};