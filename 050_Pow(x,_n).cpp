class Solution {
public:
    double myPow(double x, int n) {
        double p = x, ans = 1.0;
        long long k = n;
        if(n < 0)
            k = -k;
        while(k) {
            if(k % 2 == 1)
                ans *= p;
            p *= p;
            k /= 2;
        }
        return (n < 0) ? (1.0 / ans) : ans;
    }
};
