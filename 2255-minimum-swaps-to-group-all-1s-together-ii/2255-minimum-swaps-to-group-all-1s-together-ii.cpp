class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cntOnes = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                cntOnes++;
            }
        }
        if (cntOnes <= 1) {
            return 0;
        }
        int i = 0;
        int j = 0;
        int ans = INT_MAX;
        int cnt1 = 0;
        vector<int> temp;
        for(int i = 0;i<n;i++){
            temp.push_back(nums[i]);
        }
        for(int i = 0;i<n;i++){
            temp.push_back(nums[i]);
        }
        while (j < 2*n) {
            int Ws = j - i + 1;
            if (temp[j] == 1) {
                cnt1++;
            }
            if (Ws == cntOnes) {
                ans = min(ans, cntOnes - cnt1);
            } else {
                while (Ws > cntOnes) {
                    if (temp[i] == 1 && cnt1 > 0) {
                        cnt1--;
                    }
                    i++;
                    Ws = j - i + 1;
                }
                if (Ws == cntOnes) {
                    ans = min(ans, cntOnes - cnt1);
                }
            }
            j++;
        }
        return ans;
    }
};