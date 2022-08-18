class Solution {
public:
    int minSetSize(vector<int>& arr) {
        std::unordered_map<int,int> mp;
    for(auto i : arr)
            mp[i]++;
   
    
    std::vector<int> freq;
    int target = arr.size()/2;
    for(auto i : mp){
        if(i.second <= target)
                freq.push_back(i.second);
    }
    if(freq.size() == 0)
            return 1;
    
    sort(freq.begin(),freq.end(),greater<int>());
    
    if(freq[0] == target)
            return 1;
   
    int sum = freq[0];
    int iter = freq.size() - 1;
    int count = 1;
    for(int i = 1; i < freq.size() ; i++){
        if(sum >= target)
                break;
        sum += freq[i];
        std::cout<<target<<"\t"<<sum<<"\n";
        count++;
    }

    return count;
}
};