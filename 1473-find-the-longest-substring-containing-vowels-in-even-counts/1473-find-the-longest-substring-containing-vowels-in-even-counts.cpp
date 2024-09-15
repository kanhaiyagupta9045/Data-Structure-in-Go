class Solution {
public:
    bool check(unordered_map<char, int>& m) {
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (auto it : vowels) {
            if (m.find(it) != m.end()) {
                int a = m[it];
                if (a % 2 != 0) {
                    return false;
                }
            }
        }
        return true;
    }
    int findTheLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int n = s.size();
        unordered_map<char, int> vowel_count = {
            {'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};
        int ans = 0;
        string current_state = "00000";
        unordered_map<string, int> m;
        m[current_state] = -1;
        while (i < n) {
            if (s[i] == 'a')
                vowel_count['a']++;
            else if (s[i] == 'e')
                vowel_count['e']++;
            else if (s[i] == 'i')
                vowel_count['i']++;
            else if (s[i] == 'o')
                vowel_count['o']++;
            else if (s[i] == 'u')
                vowel_count['u']++;

            current_state[0] = vowel_count['a'] % 2 + '0';
            current_state[1] = vowel_count['e'] % 2 + '0';
            current_state[2] = vowel_count['i'] % 2 + '0';
            current_state[3] = vowel_count['o'] % 2 + '0';
            current_state[4] = vowel_count['u'] % 2 + '0';

            if(m.find(current_state)!=m.end()){
                ans = max(ans, i - m[current_state]);
            }else{
                m[current_state] =i;
            }
            i++;
        }
        return ans;
    }
};