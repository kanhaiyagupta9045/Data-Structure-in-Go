class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;

        double ans = INT_MIN;
        double sum = 0.0;
        while (j < n) {
            int wS = j - i + 1;
            sum += nums[j];
            if (wS == k) {
                double avg = sum / (double)wS;
                ans = max(ans, avg);
            } else {
                while (wS > k) {
                    sum -= nums[i];
                    i++;
                    wS = j - i + 1;
                }
                if (wS == k) {
                    double avg = sum / (double)wS;
                    ans = max(ans, avg);
                }
            }
            j++;
        }
        return ans;
    }
};