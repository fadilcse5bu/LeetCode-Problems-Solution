class Solution {
public:
    int reverse(int x) {
        int v = x, mx = INT_MAX;
        long long int ans = 0;
        while(v != 0) {
            int r = v % 10;
            if(r < 0) r *= -1;
            v /= 10;
            ans = ans * 10 + r;
            if(ans > mx) {
                ans = 0;
                break;
            }
        }
        if(x < 0) ans *= -1;
        int fans = ans;
        return fans;
    }
};
