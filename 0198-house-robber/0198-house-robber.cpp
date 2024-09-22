class Solution {
public:
    //vector<int> dp;
    // int solve(int ind , vector<int> &nums){
    //     if(ind==0){
    //         return nums[ind];
    //     }
    //     if(ind<0){
    //         return 0;
    //     }
    //     if(dp[ind]!=-1){
    //         return dp[ind];
    //     }


    //     int pick = nums[ind]+solve(ind-2,nums);
    //     int nonPick = 0 + solve(ind-1,nums);
    //     return dp[ind]= max(pick,nonPick);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        //dp.resize(n,-1);
        vector<int> dp(n,0);
        dp[0] =  nums[0];

        for(int i = 1;i<n;i++){
            int pick = nums[i];
            if(i>1){
            pick += dp[i-2];
            }
            int nonPick = dp[i-1];
            dp[i]= max(pick,nonPick);
        }
        return dp[n-1];
        //return solve(n-1,nums);
    }
};