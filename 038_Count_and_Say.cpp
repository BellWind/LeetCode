class Solution {
public:
    string countAndSay(int n) {
        if(n <= 0)
            return NULL;
        string ret = "1";
        for(int i = 1; i < n; i++)
            ret = expand(ret);
        return ret;
    }
private:
    string expand(const string &str) {
        stringstream sout;
        int cnt = 0;
        char cur = str[0];
        for (int i = 0; i <= str.size(); ++i) {
            if (str[i] == cur)
                ++cnt;
            else {
                sout << cnt << cur;
                cnt = 1;
                cur = str[i];
            }
        }
        return sout.str();
    }
};
