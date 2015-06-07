class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        ans.clear();
        if(matrix.size() == 0)
            return ans;
        mm = matrix;
        dfs(0, mm.size() - 1, 0, mm[0].size() - 1);
        return ans;
    }
private:
    vector<int> ans;
    vector<vector<int>> mm;
    void dfs(int sx, int ex, int sy, int ey) {
        int dx = sx < ex ? 1 : -1;
        int dy = sy < ey ? 1 : -1;
        for(int j = sy; j != ey; j += dy)
            ans.push_back(mm[sx][j]);
        for(int i = sx; i != ex; i += dx)
            ans.push_back(mm[i][ey]);
        ans.push_back(mm[ex][ey]);
        if(sx == ex || sy == ey) {
            return ;
        }
        dfs(ex, sx + dx, ey - dy, sy);
    }
};
