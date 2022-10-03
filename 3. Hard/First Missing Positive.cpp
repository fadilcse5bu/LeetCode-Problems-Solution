class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        bool present[len + 2];
        for(int i = 1; i <= len + 1; i++) present[i] = false;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0 && nums[i] <= len) present[nums[i]] = true;
        }
        
        int min_integer_value;
        for(int i = 1; i <= len + 1; i++) {
            if(present[i] == false) {
                min_integer_value = i;
                break;
            }
        }
        return min_integer_value;
    }
};
