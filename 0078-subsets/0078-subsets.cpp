class Solution {
public:
    vector<vector<int>> ans;
    void f(int j, int n, vector<int>& arr, int mask) {

        if (j == n) {
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                if (mask & 1 << i) {
                    temp.push_back(arr[i]);
                }
            }
            ans.push_back(temp);
            return;
        }
        mask = mask | (1 << j);
        f(j + 1, n, arr, mask);
        mask = mask & ~(1 << j);
        f(j + 1, n, arr, mask);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        f(0,nums.size(),nums,0);
        return ans;
    }
};