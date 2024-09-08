class Solution {
public:
    string help(string num) {
        int number = stoi(num);
        int n = (int)(log2(number));

       return bitset<64>(number).to_string().substr(64 - n - 1);
    }
    string convertDateToBinary(string date) {
        int n = date.size();
        string ans = "";

        string temp = date.substr(0, 4);
        ans += help(temp);
        ans += '-';
        string temp1 = date.substr(5, 2);
        ans += help(temp1);
        ans += '-';

        string temp2 = date.substr(8, 2);
        ans += help(temp2);

        return ans;
    }
};