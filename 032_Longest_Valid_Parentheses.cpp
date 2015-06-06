class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() == 0)
            return 0;
        int ans = 0;
        int *dp = new int[s.size()];
        for(int i = 0; i < s.size(); i++)
            dp[i] = 0;
        for (int i = s.size() - 2; i >= 0; i--) {
            if (s[i] == ')')
                dp[i] = 0;
            else {
                int j = (i + 1) + dp[i + 1];
                if (j < s.size() && s[j] == ')') {
                    dp[i] = dp[i + 1] + 2;
                    if (j + 1 < s.size())
                        dp[i] += dp[j + 1];
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
