class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int prodt = 1;
        int ans = INT_MIN;
        for(int i = 0;i<n;i++){
            prodt = prodt*nums[i];
            ans = max(prodt,ans);
            if(prodt==0){
                prodt =1;
            }
        }
        prodt = 1;
        for(int i = n-1;i>=0;i--){
            prodt = prodt*nums[i];
            ans = max(prodt,ans);
            if(prodt==0){
                prodt =1;
            }
        }
        return ans;
    };
};