class Solution {
public:
    string helper(string temp){
        string ans = "";
        for(int i = 0;i<temp.size();i++){
            char ch = temp[i];
            int pos = abs(ch-'a');

            char new_char = 'a' + (pos+1)%26;

            ans +=new_char;
        }
        return ans;
    }
    char kthCharacter(int k) {
        string word = "a";

        while(word.size()<k){
            string temp = helper(word);
            word = word +temp;
            if(word.size()>k){
                break;
            }
        }
        return word[k-1];
    }
};