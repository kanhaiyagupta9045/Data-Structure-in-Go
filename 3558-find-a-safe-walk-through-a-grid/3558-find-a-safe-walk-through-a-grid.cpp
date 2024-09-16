class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        health = health - (grid[0][0] == 1 ? 1 : 0);
        q.push({health, {0, 0}});
        set<int> s;
        while (!q.empty()) {
            auto it = q.top();
            q.pop();
            int row = it.second.first;
            int col = it.second.second;
            int current_health = it.first;
            if (row == m - 1 && col == n - 1) {
                if(current_health>=1){
                    return true;
                }
            }

            for (int i = 0; i < 4; i++) {
                int newRow = row + dy[i];
                int newCol = col + dx[i];

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&!vis[newRow][newCol]) {
                    if (grid[newRow][newCol] == 1) {
                        q.push({current_health - 1, {newRow, newCol}});
                    } else {
                        q.push({current_health, {newRow, newCol}});
                    }
                    vis[newRow][newCol] = 1;
                }
            }
        }
        return false;
    }
};