class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int n = a + b + c;
        int curra = 0, currb = 0, currc = 0;

        string ans = "";
        for (int i = 0; i < n; i++) {
            if (a >= b && a >= c && curra != 2 ||
                (a > 0 && (currb == 2 || currc == 2))) {
                ans += 'a';
                a--;
                curra++;
                currb = 0;
                currc = 0;
            } else if (c >= b && c >= a && currc != 2 ||
                       (c > 0 && (currb == 2 || curra == 2))) {
                ans += 'c';
                c--;
                currc++;
                curra = 0;
                currb = 0;
            } else if (b >= c && b >= a && currb != 2 ||
                       (b > 0 && (curra == 2 || currc == 2))) {
                ans += 'b';
                b--;
                currb++;
                curra = 0;
                currc = 0;
            }
        }
        return ans;
    }
};