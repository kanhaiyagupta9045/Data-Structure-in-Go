class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n  = arr.size();
        vector<int> prefix(n+1,0);
        prefix[0] =  arr[0];
        for(int i =0;i<n;i++){
            prefix[i+1]= prefix[i]^arr[i];
        }
        vector<int> ans;
        for(auto it : queries){
            int i = it[0];
            int j = it[1];
            int a = prefix[j+1]^prefix[i];
            ans.push_back(a);
        }
        return ans;
    }
};