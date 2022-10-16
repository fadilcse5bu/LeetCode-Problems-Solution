class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        if(num == 0) return true;
        for(int i = 1; i < num; i++) {
            int n = i, v = 0;
            while(n > 0) {
                int r = n % 10;
                n /= 10;
                v = (v * 10 + r);
            }
            if(num - i == v) return true;
        }
        return false;
    }
};
