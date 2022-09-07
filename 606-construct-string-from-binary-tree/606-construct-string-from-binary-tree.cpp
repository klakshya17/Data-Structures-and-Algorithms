class Solution {
public:
    void fun(TreeNode* root, string& ans)
    {
        ans += to_string(root->val);
        
        if(root->left==NULL && root->right==NULL)
            return;
        
        if(root->left)
        {
            ans+="(";
            fun(root->left,ans);
            ans+=")";
        }
        else
            ans+="()";
        
        if(root->right)
        {
            ans+="(";
            fun(root->right,ans);
            ans+=")";
        }
    }
    string tree2str(TreeNode* root) {
        string ans="";
        fun(root, ans);
        return ans;
    }
};