class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = n - 1;
        set<vector<int>> s;
        for (int i = 0; i < n - 2; i++) {
            int k = i + i;
            int j = n - 1;
            while (k < j) {

                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[k]);
                    temp.push_back(nums[j]);
                    s.insert(temp);
                    i++;
                    j--;
                }

                else if (nums[i] + nums[k] + nums[j] > 0) {
                    j--;
                } else {
                    k++;
                }
            }
        }
        for (auto it : s) {
            ans.push_back(it);
        }
        return ans;
    }
};