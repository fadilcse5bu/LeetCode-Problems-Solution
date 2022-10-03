class Solution {
public:
    int longestValidParentheses(string s) {
        int length = 0;
        int countLeft = 0, countRight = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') ++countLeft;
            else ++countRight;
            if(countLeft == countRight) {
                length = max(length, 2*countLeft);
            }
            if(countRight > countLeft) {
                countLeft = 0;
                countRight = 0;
            }
        }
        countLeft = 0, countRight = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == '(') ++countLeft;
            else ++countRight;
            if(countLeft == countRight) {
                length = max(length, 2*countLeft);
            }
            if(countLeft > countRight) {
                countLeft = 0;
                countRight = 0;
            }
        }
        
        return length;
    }
};
