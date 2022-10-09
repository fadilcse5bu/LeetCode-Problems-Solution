class Solution {
public:
    string convert(string s, int numRows) {
        int row = 0, counter = 1;
        vector <int> index[numRows];
        for(int i = 0; i < s.size(); i++) {
            index[row].push_back(i);
            if(row == 0 && counter == -1) {
                 counter = 1;
            }
            if(row == numRows - 1 && counter == 1) {
                counter = -1;
            }
            row += counter;
            if(numRows == 1) row = 0;
        }
        
        string convertedString;
        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j < index[i].size(); j++) {
                convertedString.push_back(s[index[i][j]]);
            }
        }
        return convertedString;
    }
};
