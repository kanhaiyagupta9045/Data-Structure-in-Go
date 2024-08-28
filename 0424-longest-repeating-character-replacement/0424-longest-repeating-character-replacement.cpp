int maxi(const map<char, int> &m) {
    auto maxElement = std::max_element(
        m.begin(),  m.end(),
        [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
            return a.second < b.second;
        });
    return maxElement->second;
}

class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;

        int ans = 0;
        map<char, int> m;
        while (j < s.size()) {
            int windowSize = j - i + 1;
            m[s[j]]++;
            int count = maxi(m);
            if (windowSize - count <= k) {
                ans = max(ans, windowSize);
            } else {
                while (windowSize - count > k) {
                    m[s[i]]--;
                    if (m[s[i]] == 0) {
                        m.erase(m[s[i]]);
                    }

                    i++;
                    windowSize = j - i + 1;
                    count = maxi(m);
                }
                if (windowSize - count <= k) {
                    ans = max(ans, windowSize);
                }
            }
            j++;
        }
        return ans;
    }
};