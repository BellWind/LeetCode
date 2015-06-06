class Solution {
public:
    int strStr(string &haystack, string &needle) {
        if(needle.size() == 0)
            return 0;
        if(haystack.size() == 0)
            return -1;
        return kmp(needle, haystack);
    }
private:
    int* next;
    void Getnextval(string &p) {
        next = new int[p.size() + 1];
        int i = 0, k = -1;
        next[0] = -1;
        while(i < p.size()) {
            if(k == -1 || p[i] == p[k]) {
                i++, k++;
                if(p[i] == p[k])
                    next[i] = next[k];
                else
                    next[i] = k;
            } else
                k = next[k];
        }
    }
    int kmp(string &w, string &t) {
        Getnextval(w);
        int i = 0, j = 0;
        while(i < t.size()) {
            if(j == -1 || t[i] == w[j]) {
                i++, j++;
                if(j == w.size())
                    return i - j;
            } else
                j = next[j];
        }
        return -1;
    }
};
