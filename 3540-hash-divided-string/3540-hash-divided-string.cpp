class Solution
{
public:
    string stringHash(string s, int k){
        int n = s.size();

        int length = n / k;
        string result = "";
        for (int i = 0; i < n; i += k){
            string temp = s.substr(i, k);
            cout<<temp<<endl;
            int sum = 0;
            for (int j = 0; j < temp.size(); j++){
                sum += (temp[j] - 'a');
            }
            char ch = char('a' + (sum % 26));
            result += ch;
        }
        return result;
    }
};