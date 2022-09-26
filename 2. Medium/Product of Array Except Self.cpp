class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        int pre[len], p = nums[0];
        pre[len - 1] = nums[len - 1];
        for(int i = len - 2; i >= 0; i--) pre[i] = pre[i+1]*nums[i];
        vector <int> ans;
        ans.push_back(pre[1]);
        for(int i = 1; i < len - 1; i++) {
            int pp = pre[i+1]*p;
            ans.push_back(pp);
            p*=nums[i];
        }
        ans.push_back(p);
        return ans;
    }
};
