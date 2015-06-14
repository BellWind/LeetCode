class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)  {
        ans.clear();
        tmp.clear();
        dfs(nums, tmp, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
private:
    vector<int> tmp;
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, vector<int> tmp, int k) {
        if(k == nums.size()) {
            sort(tmp.begin(), tmp.end());
            ans.push_back(tmp);
            return ;
        }
        dfs(nums, tmp, k + 1);
        tmp.push_back(nums[k]);
        dfs(nums, tmp, k + 1);
    }
};
