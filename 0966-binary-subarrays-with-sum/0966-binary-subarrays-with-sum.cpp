class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        int cnt = 0;
        unordered_map<int,int> m;

        for(auto it : nums){
            sum +=it;
            if(sum==goal){
                cnt++;
            }
            int target = sum-goal;
            if(m.find(target)!=m.end()){
                cnt += m[target];
            }

            m[sum]++;
        }
        return cnt;
    }
};