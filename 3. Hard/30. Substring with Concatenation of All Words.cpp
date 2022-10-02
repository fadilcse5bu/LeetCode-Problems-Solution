class Solution {
public:
    bool concatenated_substring(string sub, unordered_map <string, int> count, int len) {
        for(int i = 0; i < sub.size(); i += len) {
            string s = sub.substr(i, len);
            if(--count[s] < 0) return false;
        }
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map <string, int> count;
        int len = words.size(), single_word_len = words[0].size();
        for(int i = 0; i < len; i++) {
            count[words[i]]++;
        }
        
        vector <int> ans;
        int con_sub_len = single_word_len * len;
        for(int i = 0; i < s.size() - con_sub_len + 1; i++) {
            if(concatenated_substring(s.substr(i, con_sub_len), count, single_word_len)) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
