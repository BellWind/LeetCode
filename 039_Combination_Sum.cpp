class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        candidates.reserve(unique(candidates.begin(), candidates.end()) - candidates.begin());
        ca = candidates;
        vector<int> tmp;
        dfs(target, 0);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> ca, cur;
    void dfs(int res, int k) {
        if(res == 0) {
            ans.push_back(cur);
            return ;
        }
        if(k >= ca.size())
            return ;
        for(int i = 0; i <= res; i += ca[k]) {
            if(i > 0)
                cur.push_back(ca[k]);
            dfs(res - i, k + 1);
        }
        cur.resize(cur.size() - res / ca[k]);
    }
};
