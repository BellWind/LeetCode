class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0)
            return 0;
        int n = grid[0].size();
        dp = new int*[m];
        for(int i = 0; i < m; i++) {
            dp[i] = new int[n];
            memset(dp[i], 0, sizeof(int) * n);
        }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                int a = INT_MAX, b = INT_MAX;
                if(ck(i - 1, j, m, n))
                    a = dp[i - 1][j];
                if(ck(i, j - 1, m, n))
                    b = dp[i][j - 1];
                if(a == INT_MAX && b == INT_MAX)
                    a = b = 0;
                dp[i][j] = grid[i][j] + min(a, b);
            }
        return dp[m - 1][n - 1];
    }
private:
    int **dp;
    bool ck(int x, int y, int m, int n) {
        if(x < 0 || x >= m)
            return false;
        if(y < 0 || y >= n)
            return false;
        return true;
    }
};
