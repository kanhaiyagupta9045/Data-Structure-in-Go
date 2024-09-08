class Solution {
public:
    bool  helper(vector<int> arr, int mid, int d) {
        int n = arr.size();
        for (int i =1; i < n; i++) {
            if (arr[i] - arr[i - 1] >= mid) {
                continue;
            }else{
                if(arr[i]+d - arr[i-1]<mid){
                    return false;
                }
                arr[i]= arr[i-1]+mid;
            }
        }
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        int n = start.size();
        int low = 0;
        int high = INT_MAX;
        int ans = INT_MIN;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(helper(start,mid,d)){
                ans = max(ans,mid);
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};