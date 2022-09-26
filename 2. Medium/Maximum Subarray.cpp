class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mn = 0, mx = INT_MIN, ct = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) ++ct;
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        if(ct == 0) return mx;
        
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum < 0) sum = 0;
            mn = max(mn, sum);
        }
        return mn;
    }
};
