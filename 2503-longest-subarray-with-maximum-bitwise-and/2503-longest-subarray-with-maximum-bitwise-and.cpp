class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());

        int n = nums.size();
        int cnt =1;
        int ans =  INT_MIN;
        for(int i = 0;i<n-1;i++){
            if(nums[i]==maxi && nums[i+1]==maxi){
                cnt ++;
            }else{
                ans = max(ans,cnt);
                cnt = 1;
            }
        }
         ans = max(ans,cnt);
        return ans;
    }
};