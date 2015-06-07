class Solution {
public:
    bool canJump(vector<int>& nums) {
        dp = new bool[nums.size()];
        memset(dp, false, sizeof(dp[0]) * nums.size());
        int right = 0;
        dp[0] = true;
        for(int i = 0; (i < nums.size()) && (right < nums.size() - 1); i++) {
            int t1 = min((int)nums.size() - 1, i + nums[i]);
            if(dp[i] && right < t1) {
                int t2 = max(right + 1, i);
                for(int k = t2; k <= t1; k++)
                    dp[k] = true;
                right = t1;
            }
        }
        bool ans = dp[nums.size() - 1];
        delete[] dp;
        return ans;
    }
private:
    bool *dp;
};
