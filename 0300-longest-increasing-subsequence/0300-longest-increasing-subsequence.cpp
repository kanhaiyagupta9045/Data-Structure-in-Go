class Solution {
public:
    int f(int curr_index, int prev_index, vector<int>& nums) {
        if (curr_index == nums.size()) {
            return 0;
        }
        int take = 0;
        if (prev_index == -1 || nums[curr_index] > nums[prev_index]) {
            take =  1 + f(curr_index + 1, curr_index, nums);
        }
        int nontake = f(curr_index + 1, prev_index, nums);
        return max(take, nontake);
    }
    int lengthOfLIS(vector<int>& nums) {
        return f(0,-1,nums);
    }
};