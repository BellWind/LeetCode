class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int *cnt = new int[s.size()];
        int last[300];
        for(int i = 0; i < 300; i++) last[i] = -1;
        cnt[0] = 1, last[s[0]] = 0;
        for(int i = 1; i < s.size(); i++) {
            int c = s[i];
            if(last[c] == -1 || last[c] < i - cnt[i - 1])
                cnt[i] = cnt[i - 1] + 1;
            else
                cnt[i] = i - last[c];
            last[c] = i;
        }
        int ret = 0;
        for(int i = 0; i < s.size(); i++)
            ret = max(ret, cnt[i]);
        return ret;
    }
};
