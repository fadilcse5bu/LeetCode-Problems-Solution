class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, indx[200] = {0}, pre = 0;
        for(int i = 0; i < s.size(); i++) {
            int v = s[i];
            pre = max(pre, indx[v]);
            int df = i - pre + 1;
            ans = max(ans, df);
            indx[v] = i + 1;
        }
        return ans;
    }
};
