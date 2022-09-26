class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector <vector<int>> ve;
        if(nums.size() < 4) return ve;
        for(int i = 0; i < nums.size() - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < nums.size() - 2; j++) {
                if(j - i > 1 && nums[j] == nums[j - 1]) continue;
                for(int k = j + 1; k < nums.size() - 1; k++) {
                    if(k - j > 1 && nums[k] == nums[k - 1]) continue;
                    long long int val = (long int)target - nums[i] - nums[j] - nums[k];
                    if(val > 1000000000 || val < -1000000000) continue;
                    int vv = val;
                    
                    auto I = upper_bound(nums.begin(), nums.end(), vv) - nums.begin();
                    if(I == 0) continue;
                    --I;
                    if(nums[I] == vv && I > k) {
                        vector <int> v = {nums[i], nums[j], nums[k], vv};
                        ve.push_back(v);
                    }
                }
            }
        }
        return ve;
    }
};
