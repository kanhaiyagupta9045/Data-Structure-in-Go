class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int n =  s.size();

        for(int i = 0;i<s.size();i++){
            char ch = s[i];

            if(st.size()==0){
                st.push(ch);
            }
            else if(st.size()>0 && st.top()=='(' && ch == ')'){
                st.pop();
            }else{
                st.push(ch);
            }
        }
        return st.size();
        
    }
};