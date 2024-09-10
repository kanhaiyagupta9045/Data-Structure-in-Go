class Solution {
public:
    bool helper(int mid ,vector<int>& quantities, int k){
        int cnt  = 0;
        for(auto it : quantities){
            if(it%mid==0){
                cnt += it/mid;
            }else{
                cnt += it/mid+1;
            }
        }

        return cnt<=k;

    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int high = *max_element(quantities.begin(),quantities.end());
        int low = 1;
        int ans = 0;

        while(low<=high){
            int mid = low +(high-low)/2;
            if(helper(mid,quantities,n)==true){
                ans = mid;
                high= mid-1;
            }else{
                low= mid+1;
            }
        }
        return ans;
    }
};