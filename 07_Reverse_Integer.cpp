class Solution {
public:
    int reverse(int x) {
        const int oop = (1 << 31) - 1;
        const int oon = (1 << 31);
        int ret = 0;
        while(x) {
            if(ret > oop / 10 || ret < oon / 10)
                return 0;
            ret *= 10;
            ret += x % 10;
            x /= 10;
        }
        return ret;
    }
};
