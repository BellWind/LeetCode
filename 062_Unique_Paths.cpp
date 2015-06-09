class Solution {
public:
    int uniquePaths(int m, int n) {
        dp = new int*[m];
        for(int i = 0; i < m; i++) {
            dp[i] = new int[n];
            memset(dp[i], 0, sizeof(int) * n);
        }
        dp[0][0] = 1;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                if(ck(i - 1, j, m, n))
                    dp[i][j] += dp[i - 1][j];
                if(ck(i, j - 1, m, n))
                    dp[i][j] += dp[i][j - 1];
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
