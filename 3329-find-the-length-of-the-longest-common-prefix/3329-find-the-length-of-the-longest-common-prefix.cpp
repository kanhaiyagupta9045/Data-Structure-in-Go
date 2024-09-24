class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string> st;

        for(auto it : arr1){
            string s = to_string(it);
            int n = s.size();
            for(int  i = 1;i<=n;i++){
                st.insert(s.substr(0,i));
            }
        }
        int ans = 0;
        for(auto it : arr2){
            string s = to_string(it);
            int n = s.size();
            for(int  i = 1;i<=n;i++){
                if(st.find(s.substr(0,i))!=st.end()){
                    ans = max(ans,i);
                }
            }
        }
        return ans;
    }
};