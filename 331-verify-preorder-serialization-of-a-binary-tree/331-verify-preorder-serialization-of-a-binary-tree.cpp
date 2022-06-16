class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<int> s;
        int size = preorder.size();
        
        if(size==1){
           if(preorder[0]!='#')
                return false;
           else 
               return true;}
        if(preorder[size-1]!='#' || preorder[size-3]!='#')
            return false;
            
        // if(preorder[0]=='#')
        //     if(size>1)
        //         return false;
        //     else 
        //         return true;
        // if(preorder[size-1]!='#' || preorder[size-3]!='#')
        //     return false;
        
        for(int i=0;i<size-2;i++){
            string temp = "";
            // temp += preorder[i];
            while(preorder[i]!=',' && i<size-2){
                temp.push_back(preorder[i]);
                i++;
            }
            cout<<temp;
            if(temp.empty())
                break;
            if(temp.size()==1 && temp[0]=='#')
                if(s.empty())
                    return false;
                else 
                    s.pop();
            else{
                s.push(1);
            }
        }
        return true;
    }
};