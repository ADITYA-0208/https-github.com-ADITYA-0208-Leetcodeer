class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxi=INT_MIN;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]) maxi=max(maxi,bfs(i,j,dp,matrix,visited));
            }
        }
        return (maxi != INT_MAX) ? maxi :1;
    }
    int bfs(int i ,int j ,vector<vector<int>>& dp,vector<vector<int>>& matrix,vector<vector<int>> &visited){
        if(dp[i][j] != -1) return dp[i][j];

        int n = matrix.size(), m = matrix[0].size();
        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int maxi = 1;

        for(auto d : dir) {
            int nx = i + d.first, ny = j + d.second;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] > matrix[i][j]) {
                maxi = max(maxi, 1 + bfs(nx, ny, dp, matrix,visited));
            }
        }

        return dp[i][j] = maxi;
    }
};