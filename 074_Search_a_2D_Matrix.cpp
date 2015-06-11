class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        r = matrix.size(), c = matrix[0].size();
        if(matrix[0][0] > target || matrix[r - 1][c - 1] < target)
            return false;
        mm.clear();
        mm = matrix;
        x = findX(0, r - 1, target);
        if(mm[x][0] > target)
            x--;
        y = findY(0, c - 1, target);
        return matrix[x][y] == target;
    }
private:
    vector<vector<int>> mm;
    int r, c, x, y;
    int findX(int l, int r, int t) {
        if(l >= r)
            return r;
        int m = (l + r) >> 1;
        if(mm[m][0] >  t)
            return findX(l, m, t);
        if(mm[m][0] <= t)
            return findX(m + 1, r, t);
    }
    int findY(int l, int r, int t) {
        if(l >= r)
            return r;
        int m = (l + r) >> 1;
        if(mm[x][m] >= t)
            return findY(l, m, t);
        if(mm[x][m] <  t)
            return findY(m + 1, r, t);
    }
};
