class Solution {
public:
    vector<int> dp;
    int a(int n) {
        if (n <= 1) {
            return dp[n]=1;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
         dp[n] = a(n - 1) + a(n - 2);
         return dp[n];
    }
    int climbStairs(int n) {
        if(n==1){
            return n;
        }
        dp.resize(n + 1, -1);
        return  a(n);
    }
};