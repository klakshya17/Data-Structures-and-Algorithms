class Solution {
public:
    int maximum69Number (int num) {
        string numst = to_string(num);
        cout<<numst;
        int i=0;
        for(;i<numst.size();i++){
            if(numst[i]=='6')
                break;
        }
        if(i<numst.size())
            numst[i]='9';
        return stoi(numst);
    }
};