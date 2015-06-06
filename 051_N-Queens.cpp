class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        rv = vector<bool>(n, false);
        cv = vector<bool>(n, false);
        nd = vector<bool>(n * 2 - 1, false);
        bd = vector<bool>(n * 2 - 1, false);
        vector<string> tmp(n, string(n, '.'));
        nn = n;
        dfs(tmp, 0);
        return ans;
    }
private:
    vector<vector<string>> ans;
    vector<bool> rv, cv, nd, bd;
    int nn;
    bool Set(vector<string>& x, int r, int c) {
        if(rv[r] || cv[c] || bd[r + c] || nd[r - c + nn - 1])
            return false;
        rv[r] = cv[c] = bd[r + c] = nd[r - c + nn - 1] = true;
        x[r][c] = 'Q';
        return true;
    }
    void unSet(vector<string>& x, int r, int c) {
        x[r][c] = '.';
        rv[r] = cv[c] = bd[r + c] = nd[r - c + nn - 1] = false;
    }
    void dfs(vector<string>& cur, int k) {
        if(k == nn) {
            ans.push_back(cur);
            return ;
        }
        for(int i = 0; i < nn; i++) {
            if(Set(cur, k, i)) {
                dfs(cur, k + 1);
                unSet(cur, k, i);
            }
        }
    }
};
