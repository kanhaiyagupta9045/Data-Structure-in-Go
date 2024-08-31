#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string s1 = to_string(num1);
        string s2 = to_string(num2);
        string s3 = to_string(num3);

        int maxi = max({s1.size(), s2.size(), s3.size()});

        if (s1.size() != maxi) {
            int diff = maxi - s1.size();
            s1 = string(diff, '0') + s1;
        }
        if (s2.size() != maxi) {
            int diff = maxi - s2.size();
            s2 = string(diff, '0') + s2;
        }
        if (s3.size() != maxi) {
            int diff = maxi - s3.size();
            s3 = string(diff, '0') + s3;
        }

        string ans = "";
        for (int i = 0; i < maxi; i++) {
            int a = s1[i] - '0';
            int b = s2[i] - '0';
            int c = s3[i] - '0';

            int mini = min({a, b, c});

            ans += to_string(mini);
        }
        return stoi(ans);
    }
};
