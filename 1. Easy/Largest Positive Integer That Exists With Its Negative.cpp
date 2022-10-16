class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map <int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = 1;
        }
        
        int ans = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                int v = nums[i] * -1;
                if(mp[v] == 1) {
                    ans = max(ans, nums[i]);
                }
            }
        }
        return ans;
    }
};
