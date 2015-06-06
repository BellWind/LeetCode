class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        for(int i = 0; i < candidates.size(); i++)
            ca[candidates[i]]++;
        dfs(ca.begin(), target);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> cur;
    map<int, int> ca;
    void dfs(map<int, int>::iterator it, int res) {
        if(res == 0) {
            ans.push_back(cur);
            return;
        }
        if(it == ca.end())
            return;
        int up = min(it->second, res / it->first);
        for(int i = 0; i <= up; i++) {
            if(i > 0)
                cur.push_back(it->first);
            dfs(++it, res - i * it->first);
            --it;
        }
        cur.resize(cur.size() - up);
    }
};
