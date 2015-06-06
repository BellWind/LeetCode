class Solution {
public:
    vector<string>& generateParenthesis(int n) {
        string tmp;
        dfs(n, tmp, 0, 0);
        return ans;
    }
private:
    vector<string> ans;
    void dfs(int n, string tmp, int k, int sum) {
        if(k >= n) {
            if(sum)
                return ;
            ans.push_back(tmp);
            return ;
        }
        tmp += '(', sum++;
        dfs(n, tmp, k + 1, sum);
        for(int i = 1; i <= sum; i++) {
            tmp += ')';
            dfs(n, tmp, k + 1, sum - i);
        }
    }
};
