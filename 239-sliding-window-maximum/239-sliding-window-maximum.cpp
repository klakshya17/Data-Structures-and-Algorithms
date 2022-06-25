class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> v;
        unordered_map<int,int> um;
        priority_queue<int> pq;
        int i=0;
        for(;i<k;i++)
            pq.push(nums[i]);
        v.push_back(pq.top());
        for(;i<nums.size();i++){
            // pq.remove();
            um[nums[i-k]]+=1;
            pq.push(nums[i]);
            while(um[pq.top()]>0){
                um[pq.top()]-=1;
                pq.pop();
            }
            v.push_back(pq.top());
        }
        return v;   
    }
};