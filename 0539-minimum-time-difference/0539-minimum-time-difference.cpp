class Solution {
public:
    int findMinDifference(vector<string>& tm) {

        vector<int> v;
        for(auto it : tm){
            int hours = stoi(it.substr(0,2));
            int  minutes = stoi(it.substr(3,2));

            v.push_back(60*hours+minutes);
        }

        sort(v.begin(),v.end());

        int ans =  INT_MAX;
        for(int  i = 1;i<v.size();i++){

            int b = v[i-1];
            int a = v[i];

            if(a>=720 && b>=720){
                ans = min(ans,abs(a-b));
            }else if(a>=720 && b<720){
                int p1 = a-b;  // b--a
                int p2 = 1440-a+b; // a--b

                int diff = min(p1,p2);

                ans = min(ans,diff);
            }else{
                ans = min(ans,abs(a-b));
            }
        }
//         for (int i = 1; i < v.size(); i++) {
//     ans = min(ans, v[i] - v[i-1]);
// }

// // Consider circular difference (from last time to first time, crossing midnight)
 ans = min(ans, 1440 - v.back() + v.front());
        return ans;
    }
};