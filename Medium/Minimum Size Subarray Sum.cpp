class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sub_sum = 0, p = 0, sub_length = 0;
        for(int i = 0; i < nums.size(); i++) {
            sub_sum += nums[i];
            while(sub_sum - nums[p] >= target) {
                sub_sum -= nums[p];
                ++p;
            }
            if(sub_sum >= target) {
                if(sub_length == 0) sub_length = (i-p + 1);
                else sub_length = min(sub_length, (i-p+1));
            }
        }
        
        return sub_length;
    }
};
