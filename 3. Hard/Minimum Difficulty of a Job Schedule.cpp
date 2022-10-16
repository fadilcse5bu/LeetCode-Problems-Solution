class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int len = jobDifficulty.size();
        if(d > len) return -1;
        int dp[len][d+1];
        int mx = jobDifficulty[len-1];
        for(int i = len-1; i >= 0; i--) {
            for(int j = 0; j <= d; j++) {
                dp[i][j] = 1e8;
            } 
            mx = max(mx, jobDifficulty[i]);
            dp[i][1] = mx;
        }
        
        for(int i = 2; i <= d; i++) {
            for(int j = len - 1; j >= 0; j--) {
                int m = jobDifficulty[j];
                for(int k = j+1; k < len; k++) {
                    dp[j][i] = min(dp[j][i], dp[k][i-1]+m);
                    m = max(m, jobDifficulty[k]);
                }   
            }
        }
        //for(int i = 0; i < len; i++) cout << dp[i][2] << ' ';
        return dp[0][d];
    }
};
