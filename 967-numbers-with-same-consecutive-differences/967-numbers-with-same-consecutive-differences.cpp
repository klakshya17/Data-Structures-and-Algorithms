class Solution {
public:
    vector<int> ans;
    void find(int n,int k,int curr,int tot,int sz){
        if(sz==n){
            ans.push_back(tot);
            return;
        }
        if(curr-k>=0){
            tot=tot*10+(curr-k);
            find(n,k,curr-k,tot,sz+1);
            tot/=10; //Making total same as initial value as we can execute the next block
        }
        if(k){  // if k=0 we will be inserting the same element again
          if(curr+k<=9 ){
                tot=tot*10+(curr+k);
                find(n,k,curr+k,tot,sz+1);
                tot/=10;
            }  
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++)
        find(n,k,i,i,1);
        return ans;
    }
};