class Solution {
public:
    int fib(int n) {
        if(n<=1)
            return n;
        vector<int> num;
        num.push_back(0);
        num.push_back(1);
        n-=1;
        while(n--){
            num.push_back(num[num.size()-1] + num[num.size()-2]);
        }
        return num[num.size()-1];
        
    }
};