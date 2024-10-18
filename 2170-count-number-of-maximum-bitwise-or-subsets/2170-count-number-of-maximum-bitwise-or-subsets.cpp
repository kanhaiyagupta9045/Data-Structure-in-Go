class Solution {
public:
    vector<int> v ; // store all subsets and their or
    void f(int i , int n, vector<int> &nums, int mask){
        if(i==n){
            int total = 0;
            for(int j = 0;j<n;j++){
                if(mask & (1<<j)){
                    total = total | nums[j];
                }
            }
            if(total!=0){
              v.push_back(total);
            }
            return;
        }
        mask = mask | 1<<i;
        f(i+1,n,nums,mask);
        mask = mask & ~(1<<i);
        f(i+1,n,nums,mask);

    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n  = nums.size();
        f(0,n,nums,0);
        int maxi = *max_element(v.begin(),v.end());
        return count(v.begin(),v.end(),maxi);

    }
};