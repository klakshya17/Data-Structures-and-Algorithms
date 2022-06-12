class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0,zero=0;
        // while(left<nums.size() && zero<nums.size()){
        //     while(zero<nums.size() && nums[zero]!=0)
        //         zero++;
        //     while(left<nums.size() && nums[left]==0)
        //         left++;
        //     if(left<zero)
        //         break;
        //     if(left<nums.size() && zero<nums.size() )
        //         swap(nums[left],nums[zero]);
        // }
        while(left<nums.size()){
            zero=0;
            while(zero < nums.size() && nums[zero]!=0)
                zero++;
            if(zero>=nums.size()-1)
                break;
            left=zero;
            while(left<nums.size() && nums[left]==0 )
                left++;
            if(left>=nums.size())
                break;
            swap(nums[zero],nums[left]);
        }
    }
};