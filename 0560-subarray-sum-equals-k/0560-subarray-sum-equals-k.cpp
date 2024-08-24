class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {

        unordered_map<int,int> m;
        m[0]=1;
        int cnt  = 0;
        int sum = 0;
        for(int i = 0;i<arr.size();i++){
            sum += arr[i];
            int target =  sum - k;
            cnt+=m[target];

            m[sum]+=1;
        }
        return cnt;
        
    }
};