class Solution {
public:
    int sequence_no = 0;
    string ans;
    bool kthPermutation(vector <int>& taken, bool isTaken[], int n, int cnt, int k) {
        if(cnt >= n) {
            ++sequence_no;
            if(sequence_no == k) {
                for(int i = 0; i < n; i++) {
                    char ch = taken[i] + '0';
                    ans.push_back(ch);
                }
                return true;
            }
            else return false;
        }
        for(int i = 1; i <= n; i++) {
            if(isTaken[i] == false) {
                isTaken[i] = true;
                taken.push_back(i);
                if(kthPermutation(taken, isTaken, n, cnt + 1, k)) {
                    return true;
                }
                isTaken[i] = false;
                taken.pop_back();
            }    
        }
        
        return false;
    }
    string getPermutation(int n, int k) {
        bool isTaken[n+1];
        for(int i = 0; i <= n; i++) isTaken[i] = false;
        vector <int> taken;
        kthPermutation(taken, isTaken, n, 0, k);
        return ans;
    }
};
