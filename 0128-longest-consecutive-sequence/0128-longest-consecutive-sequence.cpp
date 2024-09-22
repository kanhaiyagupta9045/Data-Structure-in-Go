class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        unordered_set<int> m;
        for(auto it : nums){
            m.insert(it);
        }

        int ans = 1;
        for(auto it : m){
            int x = it;
            if(m.find(x-1)==m.end()){
                int cnt  =0;
                while(m.find(x)!=m.end()){
                    x = x+1;
                    cnt++;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};