class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return string("");
        int ans = strs[0].size(), k;
        for(int i = 1; i < strs.size(); i++) {
            k = 0;
            while(k < ans) {
                if(strs[i - 1][k] != strs[i][k])
                    break;
                k++;
            }
            ans = k;
        }
        if(ans == 0)
            return string("");
        return string(strs[0], 0, ans);
    }
};
