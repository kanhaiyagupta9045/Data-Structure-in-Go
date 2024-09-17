class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int dx[] = {-1, 0, +1, 0};
        int dy[] = {0, +1, 0, -1};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<int>> dis(m, vector<int>(n, 0));
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({0, {i, j}});
                }
            }
        }
        while (!q.empty()) {
            auto it = q.front();
            int row = it.second.first;
            int col = it.second.second;
            int step = it.first;
            q.pop();
            dis[row][col] = step;

            for (int  i = 0;i<4;i++){
                int nRow = dx[i]+row;
                int nCol = dy[i]+col;
                if(nRow>=0 && nRow<m && nCol>=0 && nCol<n &&!vis[nRow][nCol] && mat[nRow][nCol]==1){
                    q.push({step+1,{nRow,nCol}});
                    vis[nRow][nCol] = 1;
                }
            }
        }
        return dis;
    }
};