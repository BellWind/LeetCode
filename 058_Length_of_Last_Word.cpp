class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 0)
            return 0;
        int ed = s.size() - 1;
        while(ed >= 0 && s[ed] == ' ')
            ed--;
        int cnt = 0;
        while(ed >= 0 && s[ed] != ' ')
            ed--, cnt++;
        return cnt;
    }
};
