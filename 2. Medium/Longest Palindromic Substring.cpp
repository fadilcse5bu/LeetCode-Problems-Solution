class Solution {
public:
    string longestPalindrome(string s) {
        vector <int> even, odd;
        for(int i = 1; i <= s.size(); i++) {
            if(i % 2) odd.push_back(i);
            else even.push_back(i);
        }
        int low = 0, high = odd.size() - 1, lin, rin;
        while(low <= high) {
            int mid = (low + high) / 2;
            int b = 0, e = odd[mid] - 1;
            bool c = false;
            while(e < s.size()) {
                bool ck = true;
                for(int i = b, j = e; i <= j; i++, j--) {
                    if(s[i] != s[j]) {
                        ck = false;
                        break;
                    }
                }
                if(ck) {
                    lin = b, rin = e;
                    c = true;
                    break;
                }
                ++b, ++e;
            }
            if(c == true) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        low = 0, high = even.size() - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            int b = 0, e = even[mid] - 1;
            bool c = false;
            while(e < s.size()) {
                bool ck = true;
                for(int i = b, j = e; i <= j; i++, j--) {
                    if(s[i] != s[j]) {
                        ck = false;
                        break;
                    }
                }
                if(ck == true) {
                    if((e - b) > (rin - lin)) {
                        lin = b, rin = e;
                    }
                    c = true;
                    break;
                }
                ++b, ++e;
            }
            if(c == true) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        string st;
        for(int i = lin; i <= rin; i++) st.push_back(s[i]);
        return st;
    }
};
