class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> tmp(n);
        string ans;
        int r = 1;
        for(int i = 0; i < n; i++) {
            tmp[i] = i + 1;
            r *= (i + 1);
        }
        k--;
        for(int i = 0; i < n; i++) {
            r /= (n - i);
            ans += '0' + tmp[k / r];
            for(int j = k / r; j < n - i - 1; j++)
                tmp[j] = tmp[j + 1];
            k = k % r;
        }
        return ans;
    }
};
