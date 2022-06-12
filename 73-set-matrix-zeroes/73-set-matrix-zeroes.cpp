class Solution {
public:
    void rowzero(vector<vector<int>>& matrix,int row,int n){
        for(int i=0;i<=n;i++){
            matrix[row][i]=0;
        }
    }
    void columnzero(vector<vector<int>>& matrix,int column,int m){
        for(int i=0;i<=m;i++){
            matrix[i][column]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows,columns;
        int n = matrix[0].size()-1, m=matrix.size()-1;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(matrix[i][j]==0)
                {
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        for(auto i:rows){
            // cout<<i<<" ";
            rowzero(matrix,i,n);
        }
        for(auto i: columns){
            // cout<<i<<" ";
            columnzero(matrix,i,m);
        }
        
    }
};