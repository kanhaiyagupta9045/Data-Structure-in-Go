class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int cnt = 1;
        for(int i = 0;i<word.size()-1;i++){
            if(word[i]==word[i+1] && cnt<9){
                cnt++;
            }else{
                ans += to_string(cnt)+word[i];
                cnt=1;
            }
        }
        ans += to_string(cnt)+word[word.size()-1];
        return ans;
    }
};