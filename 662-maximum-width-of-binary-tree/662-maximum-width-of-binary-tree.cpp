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
    long long int ans = 0;
    void levelOrder(queue<pair<TreeNode*,long long int>> q){
        while(!q.empty()){
            int s = q.size();
            long long int low = INT_MAX, high = INT_MIN;
            int i = q.front().second;
            cout<<i<<" "<<endl;
            while(s--){
                
                    cout<<q.front().first->val<<" "<<q.front().second<<endl;
                
                    low = min(low,q.front().second);
                    high = max(high,q.front().second);
                    if(q.front().first->left)
                    q.push(make_pair(q.front().first->left,(q.front().second-i)*2));
                    if(q.front().first->right)
                    q.push(make_pair(q.front().first->right,((q.front().second-i)*2)+1));
                q.pop();
                ans = max(ans,high-low+1);
                
            }}}
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*,long long int>> q;
        q.push(make_pair(root,1));
        levelOrder(q);
        return ans;
        
    }
};