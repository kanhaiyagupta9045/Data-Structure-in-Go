class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int cnt  = 0;
        for(auto it : nums){
            if(it!=0){
                nums[i++]=it;
            }else{
                cnt++;
            }
        }
        int j = nums.size()-1;
        while(cnt!=0){
            nums[j--]=0;
            cnt--;
        }
    }
};