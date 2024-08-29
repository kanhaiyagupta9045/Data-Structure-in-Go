class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int ans = INT_MAX;
        int n = nums.size();
        int sum = 0;
        while (j < n) {
            int windowSize = j - i + 1;
            sum += nums[j];
            if (sum == k) {
                ans = min(ans, windowSize);
            }

            else {
                while (sum > k) {
                    ans = min(ans, windowSize);
                    sum -= nums[i];
                    i++;
                    windowSize = j - i + 1;
                }
                if (sum == k) {
                    ans = min(ans, windowSize);
                }
            }
            j++;
        }
        if (ans == INT_MAX) {
            return 0;
        }
        return ans;
    }
};