class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map <string, int> mp;
        for(int i = 0; i < words.size(); i++) {
            mp[words[i]]--;
        }
        vector <pair<int, string>> vs;
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            vs.push_back({it->second, it->first});
        }
        sort(vs.begin(), vs.end());
        vector <string> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(vs[i].second);
        }
        return ans;
    }
    
};
