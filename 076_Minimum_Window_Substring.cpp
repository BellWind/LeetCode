class Solution {
public:
    string minWindow(string s, string t) {
        string ans, tmp;
        sort(t.begin(), t.end());
        st = new int[t.size()];
        rd = new int[t.size()];
        memset(st, 0, sizeof(int) * t.size());
        memset(rd, 0, sizeof(int) * t.size());
        cnt = 0;
        for(int i = 0; i < t.size(); i++) {
            if(t[i] != t[cnt])
                t[++cnt] = t[i], st[cnt] = 1;
            else
                st[cnt]++;
        }
        cnt++;
        t.resize(cnt);
        int head = 0, tail = 0;
        while(tail < s.size()) {
            if(ck())
                break;
            int pos = lower_bound(t.begin(), t.end(), s[tail]) - t.begin();
            if(pos < t.size() && s[tail] == t[pos])
                rd[pos]++;
            tail++;
        }
        if(!ck())
            return "";
        ans = s.substr(0, tail);
        pos = lower_bound(t.begin(), t.end(), s[head]) - t.begin();
        while(head < s.size() && (pos >= t.size() || s[head] != t[pos] || rd[pos] > st[pos])) {
            if(pos < t.size() && s[head] == t[pos])
                rd[pos]--;
            head++;
            pos = lower_bound(t.begin(), t.end(), s[head]) - t.begin();
        }
        if(ans.size() >= tail - head)
            ans = s.substr(head, tail - head); 
        for(int i = tail; i < s.size(); i++) {
            pos = lower_bound(t.begin(), t.end(), s[i]) - t.begin();
            if(pos < t.size() && s[i] == t[pos])
                rd[pos]++;
            pos = lower_bound(t.begin(), t.end(), s[head]) - t.begin();
            while(head < i && (pos >= t.size() || s[head] != t[pos] || rd[pos] > st[pos])) {
                if(pos < t.size() && s[head] == t[pos])
                    rd[pos]--;
                head++;
                pos = lower_bound(t.begin(), t.end(), s[head]) - t.begin();
            }
            if(ans.size() >= i - head + 1)
                ans = s.substr(head, i - head + 1);
        }
        pos = lower_bound(t.begin(), t.end(), s[head]) - t.begin();
        while(head < s.size() && (pos >= t.size() || s[head] != t[pos] || rd[pos] > st[pos])) {
            if(pos < t.size() && s[head] == t[pos])
                rd[pos]--;
            head++;
            pos = lower_bound(t.begin(), t.end(), s[head]) - t.begin();
        }
        if(ans.size() >= s.size() - head)
            ans = s.substr(head, s.size() - head);
        delete[] st;
        delete[] rd;
        return ans;
    }
private:
    int cnt, pos, *st, *rd;
    bool ck() {
        for(int i = 0; i < cnt; i++)
            if(rd[i] < st[i])
                return false;
        return true;
    }
};
