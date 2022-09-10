class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        // Both attack and defence values are from the range [1; 100000].
        // So the array 'maxes' must fit any property value.
        const int maxes_sz = 100001;
        int       maxes[maxes_sz];
        
        // C-style array and memset for faster memory initialization.
        memset(maxes, 0, sizeof(int) * maxes_sz);
        
        // 1-st step
        // Let 'maxes' contain for any index 'attack' maximum 'defence'
        // for this concrete 'attack' value across all the 'properties'.
        for (const vector<int> &prop : properties) {
            int &m = maxes[prop[0]];
            m = max(m, prop[1]);
        }
        
        // 2-nd step
        // Let 'maxes' contain for any index 'attack' maximum 'defence'
        // for all 'attack's which are strictly greater than this concrete
        // 'attack' value.
        // Note: we start from the end of the array and aggregate maximum
        // 'defence' from the end to the start.
        // Note: in the end we stop at the zero 'attack' index but don't
        // update it, it's okay because we don't have zero 'attack' values.
        int maxv = 0;
        for (int* ptr = maxes + (maxes_sz - 1); ptr != maxes; --ptr) {
            swap(*ptr, maxv);
            maxv = max(maxv, *ptr);
        }
        
        // 3-rd step
        // Process 'properties' again with a simple counter.
        // We built the 'maxes' with the rule which makes this
        // calculations trivial.
        int res = 0;
        for (const vector<int> &prop : properties) {
            res += int(prop[1] < maxes[prop[0]]);
        }
        return res;
    }
};