class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map <int, int> mp;
        mp[0] = 1;
        long long int sum = 0, cnt = 0, cnt1 = 0;
        for(int i = 1; i < nums.size(); i++) {
            long long int s = nums[i] + nums[i-1];
            if(s % k == 0) return true;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] % k == 0) cnt++;
            sum += nums[i];
            sum %= k;
            if(mp[sum] > 0) cnt1++;
            else mp[sum] = 1;
        }
        if(cnt1 > cnt) return true;
        else return false;
    }
};
