class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int time_elapsed = 0;
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i,j}, time_elapsed});
                }
            }
        }
        int time_taken = time_elapsed;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int row = it.first.first;
            int col = it.first.second;
            int curr_time = it.second;
            time_taken = max(curr_time,time_taken);
            for (int i = 0; i < 4; i++) {
                int nRow = row + dx[i];
                int nCol = col + dy[i];

                if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1&& !vis[nRow][nCol]) {
                    vis[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, curr_time + 1});
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 &&!vis[i][j]) {
                    return -1;
                }
            }
        }
        return time_taken;
    }
};