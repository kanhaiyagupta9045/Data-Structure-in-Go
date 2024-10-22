class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || 'u';
    }
    int countvowels(unordered_map<char, int>& m) {
        return m['a'] + m['e'] + m['i'] + m['o'] + m['u'];
    }
    int maxVowels(string s, int k) {
        unordered_map<char, int> m;
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        while (j < n) {
            int wS = j - i + 1;
            if (isVowel(s[j])) {
                m[s[j]]++;
            }
            if (wS == k) {
                ans = max(ans, countvowels(m));
            } else {
                while (wS > k) {
                    if (m[s[i]] > 0) {
                        m[s[i]]--;
                        if (m[s[i]] == 0) {
                            m.erase(s[i]);
                        }
                        i++;
                        wS = j - i + 1;
                    }
                }
                if (wS == k) {
                    ans = max(ans, countvowels(m));
                }
            }
            j++;
        }
        return ans;
    }
};