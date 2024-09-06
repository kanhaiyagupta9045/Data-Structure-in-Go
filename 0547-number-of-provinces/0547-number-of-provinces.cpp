class Solution {
public:
    void dodfs(int node , vector<int> adj[] , vector<int> &vis){
        vis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dodfs(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        vector<int> vis(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
            vis[i] = 0;
        }
        int cnt  = 0;
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                dodfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;
    }
};