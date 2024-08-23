class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int maj_index = 0;
        int n = nums.size();

        for(int i =1;i<n;i++){
            if(nums[maj_index]==nums[i]){
                cnt++;
            }else{
                cnt--;
            }
            if(cnt==0){
                maj_index = i;
                cnt = 1;
            }
        }
        int cand = nums[maj_index];
        int count = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]==cand){
                count++;
            }
        }
        if(count>=n/2){
            return cand;
        }
        return -1;
    }
};