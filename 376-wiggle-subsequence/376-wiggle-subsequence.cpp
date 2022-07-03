class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2)
            return nums.size();
        
        
        
        // true-positive false-negative
        bool last=true;
        
        int i=1;
        
        for(;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                if(nums[i-1]-nums[i]<0)
                    last = true;
                else 
                    last = false;
                break;
            }
        }
        
        //initialising count with 1 considering the case of first two elements
        int count = 1;
        
        for(;i<nums.size();i++){
            if(nums[i-1]-nums[i]<0){
                if(last==true){
                    count++;
                    last = false;
                }
            }
            else if(nums[i-1]-nums[i]>0){
                if(last == false){
                    count++;
                    last = true;
                }
            }
        }
        return count;
        
    }
};