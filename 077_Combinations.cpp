class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        tmp.clear();
        dfs(tmp, 1, n, k);
        return ans;
    }
private:
    vector<int> tmp;
    vector<vector<int>> ans;
    void dfs(vector<int> tmp, int t, int n, int k) {
        if(n - t + 1 < k - tmp.size())
            return ;
        if(tmp.size() == k) {
            ans.push_back(tmp);
            return ;
        }
        for(int i = t; i <= n; i++) {
            tmp.push_back(i);
            dfs(tmp, i + 1, n, k);
            tmp.erase(tmp.end() - 1);
        }
    }
};
