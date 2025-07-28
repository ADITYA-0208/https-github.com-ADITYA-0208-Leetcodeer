class Solution {
public:
    long long calcCellCost(int i, int j, int n, int m, vector<vector<int>>& waitCost) {
        if (i == 0 && j == 0) return 1;
        if (i == n - 1 && j == m - 1) return n * m;
        return waitCost[i][j] + (1LL * (i + 1) * (j + 1));
    }

    long long dfs(int i, int j, int n, int m, vector<vector<int>>& waitCost, vector<vector<long long>>& memo) {
        if (i < 0 || j < 0) return LLONG_MAX; 
        if (i == 0 && j == 0) return 1; 

        if (memo[i][j] != -1) return memo[i][j];

        long long cost = calcCellCost(i, j, n, m, waitCost);

        long long fromTop = dfs(i - 1, j, n, m, waitCost, memo);
        long long fromLeft = dfs(i, j - 1, n, m, waitCost, memo);

        return memo[i][j] = cost + min(fromTop, fromLeft);
    }

    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        swap(m, n); // Just like your original code
        vector<vector<long long>> memo(n, vector<long long>(m, -1));
        return dfs(n - 1, m - 1, n, m, waitCost, memo);
    }
};
