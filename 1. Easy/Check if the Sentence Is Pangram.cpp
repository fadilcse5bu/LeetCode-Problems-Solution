class Solution {
public:
    bool checkIfPangram(string sentence) {
        map <char, bool> mp;
        for(int i = 0; i < sentence.size(); i++) {
            mp[sentence[i]] = true;
        }
        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(mp[ch] == false) return false;
        }
        return true;
    }
};
