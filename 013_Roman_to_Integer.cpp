class Solution {
public:
    int romanToInt(string s) {
        int wi[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ws[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int ans = 0, st = 0, slen = s.size(), klen;
        for(int i = 0; i < 13; i++) {
            klen = ws[i].size();
            while(slen - st >= klen) {
                string tmp(s, st, klen);
                if(tmp != ws[i])
                    break;
                st += klen;
                ans += wi[i];
            }
        }
        return ans;
    }
};
