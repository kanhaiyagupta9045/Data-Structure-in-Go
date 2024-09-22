class Solution {
public:
    int count(int i, int j, int m, int n) {
        if (i == 0 && j ==0) {
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        return count(i-1,j,m,n)+count(i,j-1,m,n);
    }
    int uniquePaths(int m, int n) { 
        int cnt = 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = 1;
         for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;
        for(int  i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                dp[i][j] =  dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};