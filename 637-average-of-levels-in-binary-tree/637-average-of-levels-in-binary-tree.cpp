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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        
        queue<TreeNode*>st;
        st.push(root);
        
        while(!st.empty()){
            int n = st.size();
            long int sum = 0;
            for(int i=0;i<n;i++){
                TreeNode* temp = st.front();
                sum += temp->val;
                st.pop();
                
                if(temp->left!=NULL){
                    st.push(temp->left);
                }
                if(temp->right!=NULL){
                    st.push(temp->right);
                }
            }
            
            ans.push_back((double)(1.0*sum/n));
        }
        
        return ans;
        
    }
};