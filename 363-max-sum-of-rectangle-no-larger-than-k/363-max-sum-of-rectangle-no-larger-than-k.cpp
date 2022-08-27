class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
         int ans = INT_MIN, m = size(matrix), n = size(matrix[0]);
        for (int l = 0; l < n; l++) {
            vector<int>sums(m,0);
            for (int r = l; r < n; r++) {
                for (int i = 0; i < m; i++) sums[i] += matrix[i][r];
                for (int i = 0; i < m; i++) {
                    int sum = 0;
                    for (int j = i; j < m; j++) {
                        sum += sums[j];
                        if (sum > ans && sum <= k)                               ans = sum;
                    }
                }
            }
        }
        return ans;
    }
};