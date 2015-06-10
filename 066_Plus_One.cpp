class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = 1, cnt = 0;
        while(carry && cnt < digits.size()) {
            carry += digits[cnt];
            digits[cnt] = carry % 10;
            carry /= 10;
            cnt++;
        }
        if(carry && cnt == digits.size())
            digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
