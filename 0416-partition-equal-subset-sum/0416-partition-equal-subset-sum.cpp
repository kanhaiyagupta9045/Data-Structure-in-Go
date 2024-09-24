class Solution {
public:
    bool f(int n , int sum ,vector<int> &arr,vector<vector<bool>> &dp){
        if(n>=0 && sum==0){
            return dp[n][sum] = true;
        }
        if(n==0 && sum>0){
            return dp[n][sum]= false;
        }
        if(dp[n][sum]!=false){
            return dp[n][sum];
        }
        if(sum-arr[n-1]>=0){
            return dp[n][sum] = f(n-1,sum-arr[n-1],arr,dp)|| f(n-1,sum,arr,dp);
        }else{
            return dp[n][sum]=f(n-1,sum,arr,dp);
        }
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0ll);
        if((sum&1)==1){
            return false;
        }
        int target = sum/2;
        int n = nums.size();
        vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
        //return f(n,target,nums,dp);
         dp[0][0] = true;
        
        for(int  i =1;i<n+1;i++){
            dp[i][0]=true;
        }
        for(int i = 1;i<target+1;i++){
            dp[0][i]=false;
        }
        
        for(int i = 1;i<n+1;i++){
            for(int j =  1;j<target+1;j++){
                if(j-nums[i-1]>=0){
                    dp[i][j] =  dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
};