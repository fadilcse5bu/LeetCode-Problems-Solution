class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int dp[101];
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= s.size(); i++) {
            if(s[i-1] == '0') {
                if(s[i-2] != '1' && s[i-2] != '2') return 0;
                dp[i] = dp[i-2];
            }
            else {
                dp[i] = dp[i-1];
                int num = (s[i-2]-'0') * 10 + (s[i-1]-'0');
                if(num >= 10 && num <= 26) {
                    dp[i] = dp[i-1] + dp[i-2];
                }
            }
        }
        
        return dp[s.size()];
    }
};
