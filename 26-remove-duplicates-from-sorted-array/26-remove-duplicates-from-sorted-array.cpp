class Solution {
public:
    // void pushToLast(vector<int> &nums, int first,int last){
    //     while(first<last){
    //         swap(nums[first],nums[first+1]);
    //         first++;
    //     }
    // }
    int removeDuplicates(vector<int>& nums) {
        //  TLE
        // int last = nums.size()-1;
        // for(int i=1;i<nums.size();i++){
        //     while(nums[i]==nums[i-1] && i<=last)
        //         pushToLast(nums,i,last--);
        // }
        // return last+1;
        
        int last = nums[0], left=1, pointer=left;
        while(pointer<nums.size()){
            while(pointer<nums.size() && nums[pointer]<=last )
                pointer++;
            if(pointer<nums.size()){
                last=nums[pointer];
                swap(nums[left],nums[pointer]);
                left++;
            }
        }
        return left;
    }
};