class Solution {
public:
    int f(int n , int m, string &s1, string &s2){
        if(n==0 || m==0){
            return 0;
        }
        if(s1[n-1]==s2[m-1]){
            return 1 + f(n-1,m-1,s1,s2);
        }else
        return max(f(n-1,m,s1,s2),f(n,m-1,s1,s2));
    }
    int longestCommonSubsequence(string s1, string s2) {
        return f(s1.size(),s2.size(),s1,s2);
    }
};