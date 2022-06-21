class Solution {
public:
    
    int numTrees(int n) {
        if(n==0 || n==1)
            return n;
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            int left=0, right=i-1;
            
            long long int sum=0;
            while(left<=i-1){
                sum += dp[left]*dp[right];
                left++;
                right--;
            }
            dp[i]=sum;
        }
        // for(int i=0;i<n;i++)
        //     cout<<dp[i]<<" ";
        return dp[n];
    }
};