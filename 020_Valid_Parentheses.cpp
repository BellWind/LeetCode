class Solution {
public:
    bool isValid(string s) {
        string stk;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                if(stk.size() == 0)
                    return false;
                else if(s[i] == ')' && stk[stk.size() - 1] == '(')
                    stk.erase(stk.size() - 1, 1);
                else if(s[i] == ']' && stk[stk.size() - 1] == '[')
                    stk.erase(stk.size() - 1, 1);
                else if(s[i] == '}' && stk[stk.size() - 1] == '{')
                    stk.erase(stk.size() - 1, 1);
                else
                    return false;
            } else
                stk += s[i];
        }
        return stk.size() == 0;
    }
};
