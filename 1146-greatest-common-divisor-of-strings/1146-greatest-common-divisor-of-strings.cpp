class Solution {
public:
    bool check(string& s1, string& s2, string& temp) {
        int j = temp.size();
        int n1 = s1.size();
        int n2 = s2.size();
        bool check = true;
        int i = 0;
        for ( ;i <= n1 - j; i += j) {
            string temp1 = s1.substr(i, j);
            if (temp != temp1) {
                check = false;
                break;
            }
        }
        if(i!=n1){
            return false;
        }
        if (!check) {
            return check;
        }

        if (!check) {
            return check;
        }
        int k = 0;
        for ( ;k <= n2 - j; k += j) {
            string temp1 = s2.substr(k, j);
            if (temp != temp1) {
                check = false;
                break;
            }
        }

        if(k!=n2){
            return false;
        }
        return check;
    }
    string gcdOfStrings(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        string ans = "";
        for (int i = 1; i <= min(n1, n2); i++) {
            string temp1 = s1.substr(0, i);
            string temp2 = s2.substr(0, i);
            if (temp1 == temp2) {
                if (check(s1, s2, temp1)) {
                    ans = temp1;
                }
            }
        }
        return ans;
    }
};