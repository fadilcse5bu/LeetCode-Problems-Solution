class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int sum = 0, len = nums.size();
        bool isIn[len+2];
        vector <int> ans;
        for(int i = 0; i <= len; i++) isIn[i] = false;
        for(int i = 0; i < len; i++) {
            if(isIn[nums[i]] == true) {
                ans.push_back(nums[i]);
            }
            isIn[nums[i]] = true;
            sum += nums[i];
        }
        int val = (len * (len + 1)) / 2 + ans[0] - sum;
        ans.push_back(val);
        return ans;
    }
};
