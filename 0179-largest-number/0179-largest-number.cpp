bool comparator(string& s1, string& s2) {
    string temp = s1 + s2;
    string temp1 = s2 + s1;
    if (temp >= temp1) {
        return true;
    } else {
        return false;
    }
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n =  nums.size();
        int cnt  = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]==0){
                cnt++;
            }
        }
        if(cnt==n){
            return "0";
        }
        vector<string> s;
        for (auto it : nums) {
            s.push_back(to_string(it));
        }
        sort(s.begin(), s.end(), comparator);
        string ans = "";
        for (string st : s) {
            ans +=st;
        }
       
        return ans;
    }
};