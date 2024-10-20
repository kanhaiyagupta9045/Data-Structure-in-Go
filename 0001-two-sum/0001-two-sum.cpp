class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // brute force
        // optimised approach
        int n = nums.size();

        unordered_map<int,int> m;

        for(int i = 0;i<n;i++){
            int rem = target-nums[i];
            if(m.find(rem)!=m.end()){
                return {i,m[rem]};
            }
            m[nums[i]] = i;
        }
        return {-1,-1};
    }
};