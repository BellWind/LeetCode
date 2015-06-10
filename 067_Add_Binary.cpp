class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans;
        int la = 0, lb = 0, carry = 0;
        while(la < a.size() || lb < b.size()) {
            if(la < a.size())
                carry += a[la++] - '0';
            if(lb < b.size())
                carry += b[lb++] - '0';
            ans += (char)(carry % 2 + '0');
            carry /= 2;
        }
        if(carry)
            ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
