class Solution {
public:
    void dfs(int row, int col, vector<vector<bool>>& vis,vector<vector<int>>& board, int m, int n) {
    vis[row][col] = 1;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++) {
            int nRow = row + dx[i];
            int nCol = col + dy[i];

            if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n &&
                !vis[nRow][nCol] && board[nRow][nCol] == 1) {
                dfs(nRow, nCol, vis, board, m, n);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        vector<vector<int>>& temp = grid;
        // first row
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1 && !vis[0][i]) {
                dfs(0, i, vis, grid, m, n);
            }
        }
        // last  row
        for (int i = 0; i < n; i++) {
            if (grid[m - 1][i] == 1 && !vis[m - 1][i]) {
                dfs(m - 1, i, vis, grid, m, n);
            }
        }
        // first col
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1 && !vis[i][0]) {
                dfs(i, 0, vis, grid, m, n);
            }
        }
        // last  col

        for (int i = 0; i < m; i++) {
            if (grid[i][n - 1] == 1 && !vis[i][n - 1]) {
                dfs(i, n - 1, vis,grid, m, n);
            }
        }

        // final ans
        int cnt  = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j]==1 && vis[i][j]==0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};