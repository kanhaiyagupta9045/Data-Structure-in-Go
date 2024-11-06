class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        if (is_sorted(nums.begin(), nums.end())) {
            return true;
        }
        while (true) {
            if (is_sorted(nums.begin(), nums.end())) {
                return true;
            }
            int i = -1;
            int j = -1;
            for (int k = 0; k < n - 1; k++) {
                int bit1 = __builtin_popcount(nums[k]);
                int bit2 = __builtin_popcount(nums[k + 1]);
                if (bit1 == bit2 && nums[k] > nums[k + 1]) {
                    i = k;
                    j = k + 1;
                    break;
                }
            }
            if(i==-1 || j==-1){
                break;
            }
            swap(nums[i],nums[j]);
        }
        return false;
    }
};