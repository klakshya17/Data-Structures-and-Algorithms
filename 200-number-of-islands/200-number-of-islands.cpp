class Solution {
public:
    void dfs_erase(vector<vector<char>>&grid,int i,int j){
    int n = grid.size();
    int m = grid[0].size();
    
    if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == '0'){
        return;
    }
    grid[i][j] = '0';
    dfs_erase(grid,i+1,j);
    dfs_erase(grid,i-1,j);
    dfs_erase(grid,i,j+1);
    dfs_erase(grid,i,j-1);
}
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int islands = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '1'){
                islands++;
                dfs_erase(grid,i,j);
            }
        }
    }
    return islands;
}
};