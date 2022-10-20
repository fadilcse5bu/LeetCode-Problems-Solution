class Solution {
public:
    string intToRoman(int num) {
        int ar[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string romanNumber;
        for(int i = 0; i <= 12; i++) {
            while(num >= ar[i]) {
                num -= ar[i];
                romanNumber.push_back(symbol[i][0]);
                if(symbol[i].size() == 2) romanNumber.push_back(symbol[i][1]);
            }
        }
        return romanNumber;
    }
};
