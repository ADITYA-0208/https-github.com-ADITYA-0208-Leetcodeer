class Solution {
public:
    int sum1(vector<vector<int>>& grid, vector<vector<int>>& visited, int i, int j, int n, int m) {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = 1;

        long long sum = 0;

        vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            sum += grid[x][y];

            for (auto [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    grid[nx][ny] > 0 && visited[nx][ny] == 0) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        return (int)sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0 && visited[i][j] == 0) {
                    int total = sum1(grid, visited, i, j, n, m);
                    if (total % k == 0) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
