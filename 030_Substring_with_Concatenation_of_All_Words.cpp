class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ans;
        int sz = L.size(), len = L[0].size();
        if(S.size() < sz * len)
            return ans;
        unsigned long long *HASH = new unsigned long long[S.size() + 1];
        unsigned long long *ws = new unsigned long long[S.size() + 1];
        unsigned long long *wl = new unsigned long long[sz];
        int *vis = new int[sz];
        HASH[0] = 1;
        for(int i = 1; i <= S.size(); i++)
            HASH[i] = HASH[i - 1] * 131;
        ws[0] = 0;
        for(int i = 1; i <= S.size(); i++)
            ws[i] = HASH[i] * S[i - 1] + ws[i - 1];
        for(int k = 0; k < sz; k++) {
            wl[k] = 0;
            for(int i = 1; i <= len; i++) {
                wl[k] = HASH[i] * L[k][i - 1] + wl[k];
            }
            wl[k] *= HASH[k];
        }
        for(int i = 1; i <= S.size() - sz * len + 1; i++) {
            for(int j = 0; j < sz; j++) vis[j] = 0;
            bool f1 = true;
            for(int ct = 0; ct < sz; ct++) {
                int l = i + ct * len;
                int r = l + len - 1;
                unsigned long long ck = (ws[r] - ws[l - 1]);
                unsigned long long ra = HASH[l - 1];
                bool f2 = false;
                for(int k = 0; k < sz; k++) {
                    if(vis[k] == 0 && wl[k] * ra == ck * HASH[k]) {
                        vis[k] = 1;
                        f2 = true;
                        break;
                    }
                }
                if(!f2) {
                    f1 = false;
                    break;
                }
            }
            if(f1)
                ans.push_back(i - 1);
        }
        delete []HASH;
        delete []ws;
        delete []wl;
        return ans;
    }
};
