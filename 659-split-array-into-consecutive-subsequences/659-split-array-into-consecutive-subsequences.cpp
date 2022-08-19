class Solution {
public:
    bool isPossible(vector<int>& nums) {
        vector<int> sz;
        vector<int> arr;
        int pos=0;
        for (auto x : nums) {
             pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            if (pos > 0 and arr[pos - 1] + 1 == x) {
                arr[pos - 1] = x;
                sz[pos - 1]++;
            }
            else {
                pos = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
                if (pos > 0 and arr[pos - 1] + 1 == x) {
                    arr[pos - 1] = x;
                    sz[pos - 1]++;
                }
                else {
                    arr.push_back(x);
                    sz.push_back(1);
                }
            }
        }
        for (auto x : sz) {
            if (x < 3)
                return false;

        }
        return true;
    }
};