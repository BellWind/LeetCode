class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        if(x == 0)
            return true;
        string str;
        while(x) {
            str += (char)(x % 10 + 1);
            x /= 10;
        }
        int k = 0;
        while(k <= str.size() / 2) {
            if(str[k] == str[str.size() - k - 1])
                k++;
            else
                break;
        }
        if(k > str.size() / 2)
            return true;
        else
            return false;
    }
};
