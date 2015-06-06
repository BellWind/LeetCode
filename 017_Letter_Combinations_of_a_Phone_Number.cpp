class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0)
            return ans;
        string tmp;
        dfs(ans, tmp, digits, 0);
        return ans;
    }
private:
    const string ch[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void dfs(vector<string>& ans, string tmp, const string& digits, int k) {
        if(k >= digits.size()) {
            ans.push_back(tmp);
            return ;
        }
        int c = digits[k] - '0';
        for(int i = 0; i < ch[c].size(); i++) {
            dfs(ans, tmp + ch[c][i], digits, k + 1);
        }
    }
};
