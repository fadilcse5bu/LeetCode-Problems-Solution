class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, int> mp;
        vector <int> v;
        for(int i = 0; i < nums.size(); i++) {
            if(mp[target - nums[i]] != 0) {
                v.push_back(mp[target - nums[i]] - 1);
                v.push_back(i);
            }
            mp[nums[i]] = i + 1;
        }
        return v;
    }
};
