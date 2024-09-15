class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int color) {
        int m = image.size();
        int n = image[0].size();
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        q.push({sr, sc});
        vis[sr][sc] = 1;
        int curr_color = image[sr][sc];
        image[sr][sc]=color;
        while (!q.empty()) {
            auto it =q.front();
            q.pop();
            int row = it.first;
            int col = it.second;

            for (int i = 0; i < 4; i++) {
                int nRow = row + dx[i];
                int nCol = col + dy[i];

                if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && image[nRow][nCol] == curr_color && !vis[nRow][nCol]){
                    vis[nRow][nCol] = 1;
                    image[nRow][nCol] = color;
                    q.push({nRow,nCol});
                }
            }
        }
        return image;
    }
};