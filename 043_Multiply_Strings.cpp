class complex {
public:
    double r, i;
    complex(double _r = 0.0,double _i = 0.0): r(_r), i(_i) {}
    complex operator +(const complex &argu) {
        return complex(r + argu.r, i + argu.i);
    }
    complex operator -(const complex &argu) {
        return complex(r - argu.r, i - argu.i);
    }
    complex operator *(const complex &argu)  {
        return complex(r * argu.r - i * argu.i, r * argu.i + i * argu.r);
    }
};

class Solution {
public:
    string& multiply(const string& num1, const string& num2) {
        ans.clear();
        solve(num1, num2);
        return ans;
    }
private:
    const double PI = acos(-1.0);
    vector<complex> x1, x2;
    vector<int> sum;
    string ans;
    void change(vector<complex>& y, int len) {
        for(int i = 1, j = len / 2, k; i < len - 1; i++) {
            if(i < j) swap(y[i], y[j]);
            k = len / 2;
            while(j >= k) {
                j -= k;
                k /= 2;
            }
            if(j < k)
                j += k;
        }
    }
    void FFT(vector<complex>& y, int len, int on) {
        change(y, len);
        for(int h = 2; h <= len; h <<= 1) {
            complex wn(cos(-on * 2 * PI / h), sin(-on * 2 * PI / h));
            for(int j = 0; j < len; j += h) {
                complex w(1, 0);
                for(int k = j; k < j + h / 2; k++) {
                    complex u = y[k];
                    complex t = w * y[k + h / 2];
                    y[k] = u + t;
                    y[k + h / 2] = u - t;
                    w = w * wn;
                }
            }
        }
        if(on == -1)
            for(int i = 0; i < len; i++)
                y[i].r /= len;
    }
    void solve(const string& num1, const string& num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int len  = 1;
        while((len < len1 * 2) || (len < len2 * 2))
            len <<= 1;

        x1.clear(), x2.clear();
        for(int i = 0; i < len1; i++) {
            int c = num1[len1 - 1 - i] - '0';
            x1.push_back(complex(c, 0));
        }
        for(int i = len1; i < len; i++)
            x1.push_back(complex(0, 0));

        for(int i = 0; i < len2; i++) {
            int c = num2[len2 - 1 - i] - '0';
            x2.push_back(complex(c, 0));
        }
        for(int i = len2; i < len; i++)
            x2.push_back(complex(0, 0));

        FFT(x1, len, 1);
        FFT(x2, len, 1);

        for(int i = 0; i < len; i++)
            x1[i] = x1[i] * x2[i];
        FFT(x1, len, -1);

        for(int i = 0; i < len; i++)
            sum.push_back((int)(x1[i].r + 0.5));
        sum.push_back(0);
        for(int i = 0; i < len; i++) {
            sum[i + 1] += sum[i] / 10;
            sum[i] %= 10;
        }
        len = len1 + len2 - 1;
        while(sum[len] <= 0 && len > 0) len--;
        for(int i = len; i >= 0; i--)
            ans += sum[i] + '0';
    }
};
