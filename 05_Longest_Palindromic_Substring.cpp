class Solution {
public:
    string longestPalindrome(string s) {
        pair<int, int> ans = manacher(s);
        return string(s, ans.first, ans.second);
    }
private:
    pair<int, int> manacher(string &s) {
        pair<int, int> ans(0, 0);
        int *str = new int[s.size() * 2 + 10];
        int *rad = new int[s.size() * 2 + 10];
        for(int i = 1; i <= s.size(); i++) {
			str[i << 1] = s[i - 1];
			str[i << 1 | 1] = -1;
		}
		int len = s.size() * 2 + 2;
		str[0] = -2, str[1] = str[len] = -1;
        int maxlen = 0;
        for(int i = 1, k; i < len; i++) {
            if(maxlen > i)
                rad[i] = min(rad[k * 2 - i], maxlen - i);
            else
                rad[i] = 1;
            while(str[i - rad[i]] == str[i + rad[i]])
                rad[i]++;
            if(rad[i] + i > maxlen) {
                maxlen = rad[i] + i;
                k = i;
            }
            if(ans.second < rad[i]) {
                ans.first = (i - rad[i] + 3) / 2 - 1;
                ans.second = rad[i];
            }
        }
        ans.second--;
        return ans;
    }
};
