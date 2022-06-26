class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        if(n==3)
            return 3;
        priority_queue<long long int> maxpq;
        priority_queue<long long int,vector<long long int>,greater<long long int>> minpq;
        minpq.push(1);
        minpq.push(2);
        minpq.push(3);
        minpq.push(5);
        
        int last=0;
        while(maxpq.size()<n){
            if(last!=minpq.top()){
                //pushing the next min element to max heap
                maxpq.push(minpq.top());
                // cout<<minpq.top()<<" ";
                last = minpq.top();
                minpq.push(minpq.top()*2);
                minpq.push(minpq.top()*3);
                minpq.push(minpq.top()*5);
            }
            minpq.pop();
        }
        return maxpq.top();
    }
};