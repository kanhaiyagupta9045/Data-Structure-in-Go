class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        int one =  std::count(s.begin(), s.end(), '1');
        int zero = std::count(s.begin(), s.end(), '0');
        if(one ==0 || zero ==0 || one ==n || zero ==n){
            return 0;
        }
        int j =  n-1;
        int cnt  = 0;
        while(s[j--]=='1'){
            cnt++;
        }
        if(cnt==one){
            return 0;
        }

        // where there postitions can be we can store;

        int k =  n-1;
        priority_queue<long long> pq;
        for(int i = n-1;i>=0;i--){
            if(s[i]=='1'){
                pq.push(k);
                k--;
            }
        }

        long long ans = 0;
        for(int i = n-1;i>=0;i--){
            if(s[i]=='1'){
                long long a = pq.top();
                if(i!=pq.top()){
                    ans += abs(a-i);
                }
                pq.pop();
            }
        }
        return ans;


    }
};