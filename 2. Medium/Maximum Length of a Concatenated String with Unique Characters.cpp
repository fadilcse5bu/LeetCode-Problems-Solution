class Solution {
public:
    int maxLength(vector<string>& arr) {
        int len = arr.size(), ans = 0;
        for(int i = 0; i < (1 << len); i++) {
            int v = i, length = 0;
            int ar[27] = {0};
            bool ck = false;
            for(int j = 0; j < len; j++) {
                if(v & (1 << j)) {
                    int l = arr[j].size();
                    for(int k = 0; k < l; k++) {
                        if(ar[arr[j][k] - 'a'] > 0) {
                            ck = true;
                            break;
                        }
                        ar[arr[j][k] - 'a']++;
                        length++;
                    }
                }
            }
            if(ck == false) ans = max(ans, length);
        }
        return ans;
    }
};
