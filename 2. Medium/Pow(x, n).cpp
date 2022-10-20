class Solution {
public:
    double pow(double x, int n) {
        if(n == 0) return 1.0;
        if(n % 2 != 0) {
            if(n > 0) return x * pow(x, n - 1);
            else return x * pow(x, n + 1);
        }
        else {
            double temp = pow(x, n / 2);
            return temp * temp;
        }
    }
    double myPow(double x, int n) {
        double ans = pow(x, n);
        if(n < 0) ans = 1.0 / ans;
        return ans;
    }
};
