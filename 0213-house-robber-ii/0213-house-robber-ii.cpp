class Solution {
public:
    vector<int> dp;
    int solve(int ind , vector<int> &nums){
        if(ind==1){
            return nums[ind];
        }
        if(ind<=0){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }

        int pick = nums[ind]+solve(ind-2,nums);
        int nonPick = solve(ind-1,nums);
        return dp[ind] = max(pick,nonPick);


    }

    int solve1(int ind , vector<int> &nums){
        if(ind==0){
            return nums[ind];
        }
        if(ind<0){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }

        int pick = nums[ind]+solve1(ind-2,nums);
        int nonPick = solve1(ind-1,nums);
        return dp[ind] = max(pick,nonPick);


    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // for index upto n-1
        if(n==1){
            return nums[0];
        }
        dp.resize(n,-1);
        int a = solve(n-1,nums);
        dp.clear();
        dp.resize(n,-1);
        // for index upto n-2;
        int b = solve1(n-2,nums);

        return max(a,b);

    }
};