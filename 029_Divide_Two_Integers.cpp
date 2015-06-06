class Solution {
public:
    int divide(int dividend, int divisor) {
        bool f1 = dividend < 0;
        bool f2 = divisor < 0;
        long long de = f1 ? -(long long)dividend : dividend;
        long long ds = f2 ? -(long long)divisor : divisor;
        if(de < ds)
            return 0;
        int M;
        for(M = 1; (ds << M) <= de; M += 1) ;
        M--;
        long long ans = 0;
        while(de >= 0 && M >= 0) {
            while((ds << M) <= de) {
                de -= (ds << M);
                ans += (1LL << M);
            }
            M--;
        }
        if((ans > (long long)INT_MAX) && ((f1 && f2) || ((!f1) && (!f2))))
           return INT_MAX;
        if((ans > (long long)INT_MAX + 1) && (((!f1) && f2) || (f1 && (!f2))))
           return INT_MAX;
        if(f1) ans *= -1;
        if(f2) ans *= -1;
        return (int)ans;
    }
};
