class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int n = s.size();
        map<char, int> m;
        int ans = 0;
        while (j < n) {
            int k = j - i + 1; // window size
            m[s[j]]++;

            if (m.size() == k) {
                ans = max(ans, j - i + 1);
            } else {
                while (m.size() < k) {
                    m[s[i]]--;
                    if (m[s[i]] == 0) {
                        m.erase(s[i]);
                    }
                    i++;
                    k = j - i + 1;
                }
                if (m.size() == k) {
                    ans = max(ans, k);
                }
            }
            j++;
        }

        return ans;
    }
};