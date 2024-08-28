class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        map<int, int> m;
        while (j < n) {
            int windowSize = j - i + 1;

            m[nums[j]]++;

            if (windowSize - m[1] <= k) {
                ans = max(ans, windowSize);
            } else {
                while (windowSize - m[1] > k) {
                    m[nums[i]]--;
                    if (m[nums[i]] == 0) {
                        m.erase(m[nums[i]]);
                    }
                    i++;
                    windowSize = j - i + 1;
                }
                if (windowSize - m[1] <= k) {
                    ans = max(ans, windowSize);
                }
            }
            j++;
        }
        return ans;
    }
};