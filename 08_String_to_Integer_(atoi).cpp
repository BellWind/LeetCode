class Solution {
public:
    int myAtoi(string str) {
        const string oop = "2147483647", oon = "2147483648";
        int st = 0;
        while(st < str.size() && str[st] == ' ')
            st++;
        if(st >= str.size() || !isdigit(str[st]) && str[st] != '-' && str[st] != '+')
            return 0;
        int flag = 1;
        if(str[st] == '-')
            flag = -1, st++;
        else if(str[st] == '+')
            flag = 1, st++;
        if(st >= str.size() || !isdigit(str[st]))
            return 0;
        int len = 0;
        while((st + len <= str.size()) && isdigit(str[st + len]))
            len++;
        string s = string(str, st, len);
        cout << s << endl;
        if((flag == 1) && (s.size() > oop.size() || s.size() == oop.size() && s > oop))
            return INT_MAX;
        if((flag == -1) && (s.size() > oon.size() || s.size() == oon.size() && s > oon))
            return INT_MIN;
        int i = 0, ans = 0;
        while(i < s.size() && isdigit(s[i])) {
            ans *= 10;
            ans += s[i++] - '0';
        }
        return ans * flag;
    }
};
