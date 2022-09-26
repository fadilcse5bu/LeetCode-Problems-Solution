class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        map <int, int> mp;
        int len = target.size() - stamp.size();
        vector <int> moves;
        while(1) {
            int ck1 = false;
            for(int i = 0; i <= len; i++) {
                if(mp[i] == 1) continue;
                int ck2 = true;
                for(int j = 0; j < stamp.size(); j++) {
                    if(target[i+j] != '?' && target[i+j] != stamp[j]) {
                        ck2 = false;
                        break;
                    }
                }
                if(ck2) {
                    for(int j = i; j < i+stamp.size(); j++) target[j] = '?';
                    moves.push_back(i);
                    mp[i] = 1;
                    ck1 = true;
                }
            }
            if(!ck1) break;
        }
        
        if(moves.size() != len+1) moves.clear();
        reverse(moves.begin(), moves.end());
        return moves;
    }
};
