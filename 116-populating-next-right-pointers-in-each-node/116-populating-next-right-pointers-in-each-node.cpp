/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void fun(queue<Node*> q){
        while(!q.empty()){
            int s = q.size();
            while(s){
                if(s==1){
                    q.front()->next=NULL;
                    if(q.front()->left)
                        q.push(q.front()->left);
                    if(q.front()->right)
                        q.push(q.front()->right);
                    q.pop();
                }
                    
                else{
                    Node* temp = q.front();
                    if(q.front()->left)
                        q.push(q.front()->left);
                    if(q.front()->right)
                        q.push(q.front()->right);
                    q.pop();
                        temp->next = q.front();
                
                }
                s--;
           }
        }
    }
    Node* connect(Node* root) {
        if(root==NULL)
            return{};
        // root->next = NULL;
        queue<Node*> q;
        q.push(root);
        fun(q);
        return root;
        
    }
};