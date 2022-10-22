class Solution {
public:
    string minWindow(string s, string t) {
        int hs[250] = {0}, ht[250] = {0};
        for(int i = 0; i < t.size(); i++) {
            ht[t[i]]++;
        }
        int left = 0, min_len = INT_MAX, cnt = 0, indx = -1;
        for(int i = 0; i < s.size(); i++) {
            hs[s[i]]++;
            if(hs[s[i]] <= ht[s[i]]) {
                ++cnt;
            }
            if(cnt == t.size()) {
                while(hs[s[left]] > ht[s[left]] || hs[s[left]] == 0) {
                    if(hs[s[left]] > ht[s[left]]) {
                        hs[s[left]]--;
                    }
                    ++left;
                }
                if(i - left + 1 < min_len) {
                    min_len = i - left + 1;
                    indx = left;
                }
            }
        }
        if(indx == -1) return "";
        return s.substr(indx, min_len);
    }
};
