class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> m;

        for (int i = 0; i < bills.size(); i++) {
            if (m.size() == 0 && bills[i] != 5) {
                return false;
            }
            if (bills[i] == 5) {
                m[5]++;
            } else if (bills[i] == 10) {
                if (m.size() < 1 && m[5]<1) {
                    return false;
                }
                m[5]--;
                m[10]++;
            } else {
                int a = m[5];
                int b = m[10];
                if (b==0 && a < 3) {
                    return false;
                }
                if (a > 0 && b > 0) {
                    m[10]--;
                    m[5]--;
                }else{
                    if(a>=3){
                        m[5]=a-3;
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};