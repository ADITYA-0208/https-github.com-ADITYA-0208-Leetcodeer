class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc]; 
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1}; 
        dfs(sr, sc,image, color, delRow, delCol, iniColor); 
        return image;
    }
    void dfs(int row, int col, vector<vector<int>>&image, int newColor, int delRow[], int delCol[],int iniColor) {
        image[row][col] = newColor; 
        int n = image.size();
        int m = image[0].size(); 
        for(int i = 0;i<4;i++) {
            int nrow = row + delRow[i]; 
            int ncol = col + delCol[i]; 
            if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && 
            image[nrow][ncol] == iniColor && image[nrow][ncol] != newColor) {
                dfs(nrow, ncol, image, newColor, delRow, delCol, iniColor); 
            }
        }
    }
};