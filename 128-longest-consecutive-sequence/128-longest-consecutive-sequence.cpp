class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> um;
        
        //assuming all the elements are start of a consecutive sequence
        for(int i=0;i<nums.size();i++){
            um[nums[i]]=true;
        }
        
        //finding elements who are actually the start of a consecutive sequence
        for(int i=0;i<nums.size();i++){
            if(um.find(nums[i]-1)!=um.end())
                um[nums[i]]=false;
        }
        
        // finding the longest sequence while iterating all the sequences
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(um[nums[i]]==true){
                int num = nums[i];
                int length =1;
                while(um.find(num+1)!=um.end()){
                    length++;
                    num = num+1;
                }
                ans = max(length,ans);
            }
        }
        return ans;
    }
};