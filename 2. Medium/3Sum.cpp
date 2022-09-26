class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        map <int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }
        
        vector <vector<int>> ve;
        if(nums.size() < 3) return ve;
        for(int i = 0; i < nums.size() - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < nums.size() - 1; j++) {
                if(j - i > 1 && nums[j] == nums[j - 1]) continue;
                int val = 0 - (nums[i] + nums[j]);
                if(mp[val] > j) {
                    vector <int> v = {nums[i], nums[j], val};
                    ve.push_back(v);
                }
            }
        }
        
        return ve;
    }
};
