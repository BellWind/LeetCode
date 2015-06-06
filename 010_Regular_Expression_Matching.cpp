class Solution {
public:
    bool isMatch(string& s, string& p) {
        memset(dp, -1, sizeof dp);
        return judge(s, p);
    }
private:
    int dp[128][128];
    int judge(string& s, string& p, int ks = 0, int kp = 0) {
        int slen = s.size() - ks;
        int plen = p.size() - kp;
        if(~dp[slen][plen])
            return dp[slen][plen];
        if(ks > s.size() || kp > p.size())
            return dp[slen][plen] = 0;
        if(kp == p.size())
            return dp[slen][plen] = (ks == s.size() ? 1 : 0);
        bool ret = 0;
        if(p[kp + 1] == '*') {
            if(judge(s, p, ks, kp + 2)) ret = 1;
            if(((ks < s.size() && p[kp] == '.') || s[ks] == p[kp]) && judge(s, p, ks + 1, kp)) ret = 1;

        } else if((ks < s.size() && p[kp] == '.') || s[ks] == p[kp])
            return dp[slen][plen] = judge(s, p, ks + 1, kp + 1);
        return dp[slen][plen] = ret;
    }
};
