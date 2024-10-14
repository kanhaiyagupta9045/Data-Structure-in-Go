class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq;

        for(auto it : nums){
            pq.push(it);
        }

        while(k--){
            int a = pq.top();
            pq.pop();
            ans += a;

            if(a%3==0){
                pq.push(a/3);
            }else{
                pq.push(a/3+1);
            }
        }
        return ans;
    }
};