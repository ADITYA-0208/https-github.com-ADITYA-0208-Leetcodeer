class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> result;
        int max_d = (n-1) + (m-1);
        for (int d = 0; d <= max_d; d++) {
            if (d % 2 == 0) {
                for (int i = m-1; i>=0; i--) {
                    int j = d - i;
                    if (j >=0 && j<n) {
                        result.push_back(mat[i][j]);
                    }
                }
            } else {
                for (int i=0;i<m;i++) {
                    int j = d-i;
                    if (j>=0 && j<n) {
                        result.push_back(mat[i][j]);
                    }
                }
            }
        }
        return result;
    }
};