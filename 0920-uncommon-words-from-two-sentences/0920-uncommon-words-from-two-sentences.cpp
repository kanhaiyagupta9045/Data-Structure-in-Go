#include <unordered_map>
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m1;
        unordered_map<string, int> m2;

        string temp1 = "";
        for(int i = 0;i<s1.size();i++){
            if(s1[i]!=' '){
                temp1 +=s1[i];
            }else{
                m1[temp1]++;
                temp1="";
            }
        }
        m1[temp1]++;
        temp1 = "";
        for(int i = 0;i<s2.size();i++){
            if(s2[i]!=' '){
                temp1 +=s2[i];
            }else{
                m1[temp1]++;
                temp1="";
            }
        }
        m1[temp1]++;
        vector<string> ans;
        for(auto it : m1){
            if(it.second==1){
                ans.push_back(it.first);
            }
        }

        return ans;


    }
};