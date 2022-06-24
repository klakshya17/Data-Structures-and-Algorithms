class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int i=0;
        for(;i<k;i++)
            pq.push(nums[i]);
        for(;i<nums.size();i++){
            if(nums[i]>pq.top()){
                pq.push(nums[i]);
                pq.pop();
            }
        }
        return pq.top();
    }
};