class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        mm.clear();
        if(n == 0)
            return mm;
        mm.resize(n);
        for(int i = 0; i < n; i++)
            mm[i].resize(n);
        val = 1;
        dfs(0, n - 1, 0, n - 1);
        return mm;
    }
private:
    int val;
    vector<vector<int>> mm;
    void dfs(int sx, int ex, int sy, int ey) {
        int dx = sx < ex ? 1 : -1;
        int dy = sy < ey ? 1 : -1;
        for(int j = sy; j != ey; j += dy)
            mm[sx][j] = val++;
        for(int i = sx; i != ex; i += dx)
            mm[i][ey] = val++;
        mm[ex][ey] = val++;
        if(sx == ex || sy == ey) {
            return ;
        }
        dfs(ex, sx + dx, ey - dy, sy);
    }
};
