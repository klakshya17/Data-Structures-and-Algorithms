class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0,zero=0;
        
        //not optimal
        // while(left<nums.size()){
        //     // zero=0;
        //     while(zero < nums.size() && nums[zero]!=0)
        //         zero++;
        //     if(zero>=nums.size()-1)
        //         break;
        //     left=zero;
        //     while(left<nums.size() && nums[left]==0 )
        //         left++;
        //     if(left>=nums.size())
        //         break;
        //     swap(nums[zero],nums[left]);
        // }
        
        int curr=0,prev=0;
        for(;curr<nums.size();curr++){
            if(nums[curr]!=0)
                swap(nums[prev++],nums[curr]);
        }
    }
};