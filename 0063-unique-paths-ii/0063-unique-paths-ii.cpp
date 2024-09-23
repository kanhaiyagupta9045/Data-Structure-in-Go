class Solution {
public:
    int f(int i, int j, int m, int n, vector<vector<int>>& grid,vector<vector<int>> &dp) {
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }

        int a = 0;
        int b = 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i>=1 && grid[i-1][j]!=1){
            a = f(i-1,j,m,n,grid,dp);
        }
        if(j>=1 && grid[i][j-1]!=1){
            b = f(i,j-1,m,n,grid,dp);
        }
        return dp[i][j] = a+b;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) {
            return 0;
        }
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,m,n,grid,dp);
    }
};