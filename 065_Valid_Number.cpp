class Solution {
public:
    bool isNumber(string s) {
        int st = 0, ed = s.size() - 1;
        while(st < s.size() && s[st] == ' ') st++;
        while(ed >= 0 && s[ed] == ' ') ed--;
        if(ed < st)
            return false;
        string num = s.substr(st, ed - st + 1);
        if(isInteger(num))
            return true;
        if(isDecimal(num))
            return true;
        if(isScientificNotation(num))
            return true;
        return false;
    }
private:
    int isInteger(string num) {
        int st = 0;
        if(num[st] == '-' || num[st] == '+')
            st++;
        if(num.size() - st == 0)
            return 0;
        if(num.size() - st == 1 && !isdigit(num[st]))
            return 0;
        for(int k = st; k < num.size(); k++)
            if(!isdigit(num[k]))
                return 0;
        return isdigit(num[0]) ? 1 : -1;
    }
    int isDecimal(string num) {
        int st = 0;
        if(num[st] == '-' || num[st] == '+')
            st++;
        if(num.size() - st == 0)
            return 0;
        if(num.size() - st == 1 && !isdigit(num[st]))
            return 0;
        string a;
        for(int k = st; k < num.size(); k++) {
            if(num[k] == '.') {
                a = num.substr(st, k - st);
                if(a.size() != 0 && isInteger(a) != 1)
                    return 0;
                a = num.substr(k + 1, num.size() - k - 1);
                if(a.size() != 0 && isInteger(a) != 1)
                    return 0;
                return isdigit(num[0]) ? 1 : -1;
            }
        }
        return 0;
    }
    int isScientificNotation(string num) {
        if(num.size() == 0)
            return 0;
        if(num.size() == 1 && !isdigit(num[0]))
            return 0;
        string a;
        for(int i = 0; i < num.size(); i++) {
            if(num[i] == 'e' || num[i] == 'E') {
                a = num.substr(0, i);
                if(!isInteger(a) && !isDecimal(a))
                    return 0;
                a = num.substr(i + 1, num.size() - 1 - i);
                if(!isInteger(a))
                    return 0;
                return isdigit(num[0]) ? 1 : -1;
            }
        }
        return 0;
    }
};
