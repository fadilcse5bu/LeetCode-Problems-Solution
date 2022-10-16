class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; i++) {
            int n = nums[i], v = 0;
            while(n > 0) {
                int r = n % 10;
                n /= 10;
                v = (v * 10 + r);
            }
            nums.push_back(v);
        }
        
        map<int, int> mp;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(mp[nums[i]] == 0) {
                ++ans;
                mp[nums[i]]++;
            }
        }
        return ans;
    }
};
