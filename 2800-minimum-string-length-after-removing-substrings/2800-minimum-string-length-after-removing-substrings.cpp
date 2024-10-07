class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if(st.size()==0){
                st.push(s[i]);
            }else if(st.size()>0 && st.top()=='A' && s[i]=='B'){
                st.pop();
            }else if(st.size()>0 && st.top()=='C' && s[i]=='D'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        return st.size();
    }
};