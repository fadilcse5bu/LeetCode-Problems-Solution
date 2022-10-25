class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int wordIndx = 0, charIndx = 0, len1 = word1.size();
        for(int i = 0; i < len1; i++) {
            int wordLen = word1[i].size();
            for(int j = 0; j < wordLen; j++) {
                if(charIndx == word2[wordIndx].size()) {
                    charIndx = 0;
                    wordIndx++;
                }
                if(wordIndx == word2.size()) return false;
                if(word1[i][j] != word2[wordIndx][charIndx]) return false;
                charIndx++;
            }
        }
        if(wordIndx != word2.size() - 1 || charIndx != word2[wordIndx].size()) return false;
        return true;
    }
};
