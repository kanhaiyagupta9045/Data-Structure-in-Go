class Solution {
public:
    void dfs(int row, int col, vector<vector<bool>>& vis,vector<vector<char>>& board, int m, int n) {
        vis[row][col] = 1;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++) {
            int nRow = row + dx[i];
            int nCol = col + dy[i];

            if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n &&
                !vis[nRow][nCol] && board[nRow][nCol] == 'O') {
                dfs(nRow, nCol, vis, board, m, n);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        vector<vector<char>>& temp = board;
        // first row
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O' && !vis[0][i]) {
                dfs(0, i, vis, board, m, n);
            }
        }
        // last  row
        for (int i = 0; i < n; i++) {
            if (board[m - 1][i] == 'O' && !vis[m - 1][i]) {
                dfs(m - 1, i, vis, board, m, n);
            }
        }
        // first col
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) {
                dfs(i, 0, vis, board, m, n);
            }
        }
        // last  col

        for (int i = 0; i < m; i++) {
            if (board[i][n - 1] == 'O' && !vis[i][n - 1]) {
                dfs(i, n - 1, vis, board, m, n);
            }
        }

        // final ans

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(temp[i][j]=='O' && vis[i][j]==1){
                    board[i][j]='O';
                }else{
                    board[i][j]='X';
                }
            }
        }
    }
};