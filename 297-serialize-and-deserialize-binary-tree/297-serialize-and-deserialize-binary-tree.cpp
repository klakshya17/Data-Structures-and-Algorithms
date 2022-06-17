/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string ans;
    void levelOrder(queue<TreeNode*> q){
        while(!q.empty()){
            long int s = q.size();
            while(s--){
                if(q.front()!=NULL)
                {
                    ans+= to_string(q.front()->val);
                    ans.push_back(',');

                    if(q.front()->left)
                        q.push(q.front()->left);
                    else
                        q.push(NULL);

                    if(q.front()->right)
                        q.push(q.front()->right);
                    else
                        q.push(NULL);
                }
                
                else{
                    ans.push_back('#');
                    ans.push_back(',');}

                q.pop();
            }
        }
    }
    string serialize(TreeNode* root) {
        //traverse in level order and keep nulls as #
        //keep comma seperated values
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        levelOrder(q);
        cout<<ans<<" ";
        return ans;
    }
    
    void lOrder(queue<TreeNode*> q,string data,int i){
        // int n=2;
        while(!q.empty()){
            cout<<q.size()<<" ";
            // cout<<n<<" ";
            int s=q.size()*2;
            int k=0;
            // cout<<k;
            for(int j=0;j<s;j++){
                string temp="";
                while(i<data.size() && data[i]!=',' ){
                    temp.push_back(data[i++]);
                }
                // cout<<temp<<" ";
                if(temp!="#"){
                    int val = stoi(temp);
                    TreeNode* node = new TreeNode(val);
                    if(k==0){
                        q.front()->left = node;
                        k=1;}
                    else {
                        q.front()->right = node;
                        k=0;
                        q.pop();}
                    
                    q.push(node);
                }
                else{
                    if(k==0){
                        q.front()->left = NULL;
                        k=1;}
                    else {
                        q.front()->right = NULL;
                        k=0;
                        q.pop();}
                    
                }
                i++;
            }
        }
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n=0,i=0;
        if(data.size()<1)
            return {};
        TreeNode* head = NULL;
            string temp="";
            while(data[i]!=',' && i<data.size()-1){
                temp.push_back(data[i++]);
            }
        // cout<<temp;
            if(temp!="#" && temp.size()>0){
                int val = stoi(temp);
                TreeNode* node = new TreeNode(val);
                head = node;
            }
            if(head!=NULL){
                queue<TreeNode*> q;
                q.push(head);
                lOrder(q,data,++i);
            }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));