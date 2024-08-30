class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        int ans = 0;
        int count_even = 0;
        while (j < n) {
            if(nums[j]%2==1){
                cnt++;
                count_even = 0;
            }
            while (cnt == k) {
                cnt -= nums[i] % 2;
                count_even++;
                i++;
            }
            ans +=count_even;
            j++;
        }
        return ans;
    }
};
