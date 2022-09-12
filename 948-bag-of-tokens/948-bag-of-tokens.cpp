class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int start = 0, end = n-1;
        int score = 0, ans = 0;
        while(start <= end){
            if(tokens[start] <= power){
                score++;
                ans = max(score,ans);
                power -= tokens[start];
                start++;
            }
            else if(score && end > start + 1){
                score--;
                power += tokens[end];
                end--;
            }
            else break;
        }
        return ans; 
    }
};
